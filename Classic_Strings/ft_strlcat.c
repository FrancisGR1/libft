/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:01:31 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:22 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;
	size_t	total;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	total = dlen + slen;
	i = 0;
	if (size <= dlen)
		return (slen + size);
	while (i < size - dlen - 1 && src[i])
	{
		dst[i + dlen] = src[i];
		i++;
	}
	dst[i + dlen] = 0;
	return (total);
}
/*
   int main	(int argc, char **argv)
   {
	char *s1 = argc > 1 ? argv[1] : "hello";
	char *s2 = argc > 2 ? argv[2] : "goodby";
	int  num = argc > 3 ? atoi(argv[3]) : 5;
	int result = ft_strlcat(s1, s2, num);

	printf("Before: %s \nAfter: %s (%d)\n", s1, s2, result) ;
		return (0);
   }
*/
