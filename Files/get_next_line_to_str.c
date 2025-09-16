/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:38:38 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:39:40 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h"

static bool	init(t_line **line)
{
	*line = malloc(sizeof(t_line));
	if (*line == NULL)
		return (false);
	(*line)->old = NULL;
	(*line)->new = NULL;
	(*line)->nl = false;
	return (true);
}

static t_string	*res(t_line *line)
{
	t_string	*result;

	if (!line)
		return (NULL);
	result = str_create(line->new);
	free(line->new);
	free(line);
	return (result);
}

t_string	*get_next_line_to_str(int fd)
{
	static char	buf[MAX_FDS][BUFFER_SIZE + 1];
	t_line		*l;
	int			i;
	int			j;

	if (fd <= 2 || fd > MAX_FDS || !init(&l))
		return (NULL);
	while (!l->nl && (buf[fd][0] || (read(fd, buf[fd], BUFFER_SIZE) > 0)))
	{
		l->old = l->new;
		l->new = ft_strjoin_until(l->old, buf[fd], '\n');
		free(l->old);
		i = 0;
		j = 0;
		while (buf[fd][i])
		{
			if (l->nl)
				buf[fd][j++] = buf[fd][i];
			if (buf[fd][i] == '\n')
				l->nl = true;
			buf[fd][i] = 0;
			i++;
		}
	}
	return (res(l));
}

// Usage example
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("t8.shakespeare.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
}
*/
