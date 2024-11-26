/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:19:57 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:18:53 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h"

int	ft_getc(int fd)
{
	char	c;
	ssize_t	bytes_read;

	c = 0;
	if (fd < 0)
		return (-1);
	bytes_read = read(fd, &c, 1);
	if (bytes_read == -1)
		return (-1);
	if (!c || !bytes_read)
		return (0);
	return (c);
}
