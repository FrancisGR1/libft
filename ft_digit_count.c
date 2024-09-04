/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:28:15 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/17 21:48:59 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digit_count(long int n, int divisor)
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
		n = n / divisor;
	}
	return (digits);
}

/*
int main (int c, char **v)
{
	char *arr = digit_count(atoi(v[1]), 10);
	printf("%s\n", arr);
}
*/
