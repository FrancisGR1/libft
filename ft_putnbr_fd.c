/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:18:02 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/11 11:33:51 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;
	char		buff[11];
	int			i;

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
	i--;
	while (i >= 0)
		write(fd, &buff[i--], 1);
}
/*
int main(int c, char **v)
{
	int n = atoi(v[1]);
	ft_putnbr_fd(n, 1);
}
*/
