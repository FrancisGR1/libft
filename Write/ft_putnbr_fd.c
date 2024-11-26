/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:18:02 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:18:58 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write.h"

int	ft_putnbr_fd(int n, int fd)
{
	long int	ln;
	char		buff[11];
	int			i;
	int			cnt;

	ln = n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	if (ln == 0)
		write(fd, "0", 1);
	i = 0;
	while (ln)
	{
		buff[i] = (ln % 10) + '0';
		ln /= 10;
		i++;
	}
	cnt = i;
	i--;
	while (i >= 0)
		write(fd, &buff[i--], 1);
	return (cnt);
}
/*
int	main(int c, char **v)
{
	int	n;

	n = atoi(v[1]);
	ft_putnbr_fd(n, 1);
}
*/
