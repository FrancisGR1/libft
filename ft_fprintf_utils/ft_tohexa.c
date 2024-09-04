/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:10:05 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/20 12:18:23 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static char	ft_base_char(char to_format, unsigned long n)
{
	unsigned char	c;
	int				l;

	c = '\0';
	if (to_format == 'l')
		l = 32;
	else if (to_format == 'u')
		l = 0;
	if (n <= 9)
		c = n + '0';
	else if (n >= 10 && n <= 32)
		c = 65 + (n - 10) + l;
	return (c);
}

// to_format:
//	'u' - uppercase
//	'l' - lowercase

int	ft_tohexa(int fd, char to_format, unsigned long n)
{
	unsigned char	buff[22];
	int				i;
	int				count;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	count = 0;
	i = 0;
	while (n)
	{
		buff[i] = ft_base_char(to_format, n % 16);
		n = n / 16;
		i++;
	}
	while (--i >= 0)
	{
		count++;
		write(fd, &buff[i], 1);
	}
	return (count);
}
/*
int main(int c, char **v)
{
	unsigned int num = c > 1 ? atoi(v[1]) : 10;
	//ft_tohexa('u','h', num);
	//printf("\n%x // printf\n", num);
	//ft_tohexa('l', 'm', (unsigned long)&num);
	//printf("\n%p // printf\n",&num);
	//int count = ft_tohexa('l', 'h', num);
	//printf("\n%d\n",  count);	
	//int count2 = printf("%x",num);
	//printf("\n%d // printf\n", count2);
	
	//memory test
	int memlen = printf("%p", (void *)&num);
	printf("\n");
	int memlen2 = ft_tohexa('l', 'm', (unsigned long) &num);
	printf("\n %d || %d", memlen, memlen2);
}
*/
