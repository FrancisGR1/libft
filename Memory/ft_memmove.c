/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:56:47 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:15:17 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;

	if (!dest && !src)
		return (0);
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	if (a < b)
	{
		while (n--)
			*a++ = *b++;
	}
	else
	{
		while (n--)
			a[n] = b[n];
	}
	return (dest);
}
/*
int main (void)
{
	char	arr[] = "Testestesfd";
	char	arr1[] = "TESTETSETEESDF";
	char	arr2[] = "Testestesfd";
	char	arr3[] = "TESTETSETEESDF";

	ft_memmove(arr3+5, arr2+5, 5);
	memcpy(arr1+5, arr+5, 5);
	printf("arr3: %s\n", arr3);
	printf("arr1: %s\n", arr1);
}
*/
/*https://www.youtube.com/watch?v=DGwdAQauEV4&ab_channel=PortfolioCourses*/
/*https://stackoverflow.com/questions/43088070/
meaning-of-overlapping-when-using-memcpy
 * https://www.youtube.com/watch?v=TGlePWhNgY0*/
