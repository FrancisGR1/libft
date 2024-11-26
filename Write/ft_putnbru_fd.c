/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:33:07 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:18:58 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write.h"

int	ft_putnbru_fd(unsigned int n, int fd)
{
	int		i;
	int		count;
	char	buff[22];

	i = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	count = ft_digit_count(n, 10);
	while (n)
	{
		buff[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	while (--i >= 0)
		write(fd, &buff[i], 1);
	return (count);
}
/*
int	main(int c, char **v)
{
	char	*p;

	p = malloc(10 * sizeof(int));
	ft_putnbru_fd(12345678, 1);
	printf("%s\n", p);
}
*/
