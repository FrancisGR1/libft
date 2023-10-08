/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:08:58 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/08 10:50:12 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	n;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	n = size - 1;
	while (*src && n)
	{
		*dst++ = *src++;
		n--;
	}
	*dst = '\0';
	return (len);
}
/*
   int	main(int c, char **v)
   {
   char arr[40];
   char arr2[40];
   int size;
   if (c > 1)
   memcpy(arr, v[1], 40);
   else
   strcpy(arr, "Hello");
   if (c > 2)
   memcpy(arr2, v[2], 40);
   else
   strcpy(arr, "Goodbye");
   if (c > 3)
   size = atoi(v[3]);
   else
   size = 10;
   printf("Dst before: %s\nSrc before: %s\n", arr, arr2);
   int length = ft_strlcpy(arr, arr2, size);
   printf("ft_strlcpy: %s -> %d\n", arr, length);
   }
*/
/*https://github.com/freebsd/freebsd-src/blob/master/sys/libkern/strlcpy.c*/
