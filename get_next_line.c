/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:16:25 by frmiguel          #+#    #+#             */
/*   Updated: 2023/11/12 20:32:13 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_line_str
{
	char *old;
	char *new;
	bool nl;
}	t_line;


static void init(t_line **line)
{
	*line = malloc(sizeof *line);
	(*line)->old = NULL;
	(*line)->new = NULL;
	(*line)->nl = false;
}

//Frees the structure initialized and returns the new line
static char *res(t_line *line)
{
	char *result;

	result = line->new;
	free(line);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	t_line		*l;
	int			i;
	int			j;

	init(&l);
	while (!l->nl && (buf[0] || (read(fd, buf, BUFFER_SIZE) > 0)))
	{
		l->old = l->new;
		l->new = ft_strjoin_until(l->old, buf, '\n');
		free(l->old);
		i = 0;
		j = 0;
		while (buf[i])
		{
			if (l->nl)
				buf[j] = buf[i];
			if (buf[i] == '\n')
				l->nl = true;
			buf[i] = 0;
			j++;
			i++;
		}
	}
	return (res(l));
}
