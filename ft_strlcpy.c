/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:08:58 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/04 19:13:15 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
size_t	strlcpyBSD (char * __restrict dst, 
const char * __restrict src, size_t dsize)
{
	const char *osrc = src;
	size_t nleft = dsize;

	if (nleft != 0) {
		while (--nleft != 0) {
			if ((*dst++ = *src++) == '\0')
				break;
		}
	}
	if (nleft == 0) {
		if (dsize != 0)
			*dst = '\0';
		while (*src++)
			;
	}

	return(src - osrc - 1);
}
*/
/*https://github.com/freebsd/freebsd-src/blob/master/sys/libkern/strlcpy.c*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	n;

	len = 0;
	while (src[len++])
		;
	if (size == 0)
		return (len);
	if (len < size)
	{
		while (*src && n--)
			*dst++ = *src++;
		dst[len] = '\0';
	}
	else
	{
		while (*src && n--)
			*dst++ = *src++;
		n = size;
		dst[size - 1] = '\0';
	}
	return (len - 1);
}
/*
int	main(void)
{
	char arr[] = "hello";
	char arr2[] = "goodbye";
	int length = ft_strlcpy(arr, arr2, 5);
	int stdlength = strlcpyBSD(arr, arr2, 5);
	printf("ft_strlcpy: %d\n", length);
	printf("strlcpy: %d\n", stdlength);
	printf("strlen: %lu\n", strlen(arr2));
}
*/
