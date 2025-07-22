/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:44:28 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:18 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

static int	digit_count(long int n)
{
	int	digits;

	if (n == 0)
		return (1);
	digits = 0;
	if (n < 0)
	{
		digits++;
		n = -n;
	}
	while (n)
	{
		digits++;
		n = n / 10;
	}
	return (digits);
}

static char	*handle_zero(char *p)
{
	p = malloc(2 * sizeof(char));
	if (!p)
		return (NULL);
	p[0] = '0';
	p[1] = '\0';
	return (p);
}

static char	*putnbr(long int n, char *ptr, int len)
{
	int	i;

	i = len - 1;
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	while (n)
	{
		ptr[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	int			digits;
	long int	num;
	char		*p;

	num = n;
	digits = digit_count(num);
	p = NULL;
	if (num == 0)
	{
		p = handle_zero(p);
		return (p);
	}
	p = malloc((digits + 1) * sizeof(char));
	if (!p)
		return (NULL);
	p = putnbr(num, p, digits);
	return (p);
}
/*
int main (int c, char **v)
{
	char	*arr;

	arr = ft_itoa(atoi(v[1]));
	printf("%s\n", arr);
}
*/
