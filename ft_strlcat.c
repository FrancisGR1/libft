/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:01:31 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/04 20:42:46 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t strlcatBSD(char *dst, const char *src, size_t dsize)
{
	const char *odst = dst;
	const char *osrc = src;
	size_t n = dsize;
	size_t dlen;

	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	n = dsize - dlen;
	if (n-- == 0)
		return(dlen + strlen(src));
	while (*src != '\0') {
		if (n != 0) {
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return(dlen + (src - osrc));
}


/*https://github.com/libressl/openbsd/blob/master/src/lib/libc/string/strlcat.c*/
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	char	*p_dest;

	len = 0;
	p_dest = dest;
	while (*dest)
	{
		printf("%c ", *dest);
		dest++;
		len++;
	}
	if (size == 0)
		return(len);
	while (*src && size--)
	{
		printf("%c ", *dest);
		*dest++ = *src++;
		len++;
	}
	*dest = '\0';
	return (len + 1);	
}

size_t strlcatGPT(char *dest, const char *src, size_t size)
{
    size_t len = 0;
    char *dest_end = dest;

    // Calculate the length of dest, and find the end of dest
    while (*dest_end)
    {
        len++;
        dest_end++;
    }

    // Calculate the available space for concatenation
    size_t available_space = size > len ? size - len - 1 : 0;

    // Copy characters from src to dest
    while (*src && available_space)
    {
        *dest_end++ = *src++;
        available_space--;
    }

    // Null-terminate the resulting string
    *dest_end = '\0';

    // Return the total length of the concatenated string
    return len + (src - src); // Equivalent to len + strlen(src)
}


int main ()
{
	char str[] = "Hello";
	char str2[] = "Worldle";
	char str3[] = "Hello";
	char str4[] = "Worldle";
	char str5[] = "Hello";
	char str6[] = "Worldle";
	int mine = ft_strlcat(str, str2, 11);
	int std = strlcatBSD(str3, str4, 11);
	int gpt = strlcatGPT(str5, str6, 11);

	printf("ft_strlcat = %d, %s\n", mine, str);
	printf("strlcatBSD = %d, %s\n", std, str3);
	printf("strlcatGPT = %d, %s\n", gpt, str5);
	return 0;
}

