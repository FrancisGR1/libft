/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:16:25 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:19:03 by frmiguel         ###   ########.fr       */
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

static char	*res(t_line *line)
{
	char	*result;

	if (!line)
		return (NULL);
	result = line->new;
	free(line);
	return (result);
}

char	*get_next_line(int fd)
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
