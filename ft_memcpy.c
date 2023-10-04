/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:44:05 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/04 15:51:35 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*a;
	char	*b;
	
	a = (char *)dest;
	b = (char *)src;
	while (n--)
		*a++ = *b++;
	return (dest);	
}
/*
int main (void)
{
        char arr[] = "Teste";
        char arr1[] = "Hello";
        char arr2[] = "Teste";
        char arr3[] = "Hello";

        ft_memcpy(arr1, arr, 5);
        memcpy(arr3, arr2, 5);
        printf("arr3: %s\n", arr3);
        printf("arr1: %s\n", arr1);
}
*/
