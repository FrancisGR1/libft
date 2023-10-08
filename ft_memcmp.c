/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:07:59 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/08 18:23:08 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
		n--;
	}
	return (0);
}
/*
int main (int c, char **v)
{
	char *s1 = c > 1 ? v[1] : "Aello";
	char *s2 = c > 2 ? v[2] : "Bello";
	int num = c > 3 ? atoi(v[3]) : 2;
	
	int result = ft_memcmp(s1, s2, num); 
	int result1 = memcmp(s1, s2, num); 
	printf("%d\n", result);
	printf("%d\n", result1);
}
*/
