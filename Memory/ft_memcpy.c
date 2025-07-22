/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:55:13 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:15:17 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	if (!dest || !src)
		return (0);
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	while (n--)
		*a++ = *b++;
	return (dest);
}

/*
int	main(void)
{
	char	arr[] = {'\0'};
	char	arr1[] = {'\0'};
	char	arr2[] = {'\0'};
	char	arr3[] = {'\0'};

	ft_memcpy(arr, arr1, 5);
	memcpy(arr2, arr3, 5);
	printf("arr3: %s\n", arr);
	printf("arr: %s\n", arr);
}
*/
