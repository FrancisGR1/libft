/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:01:31 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/07 00:41:44 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		return (dlen + size);
	while (i < size - dlen - 1 && src[i])
	{
		dst[i + dlen] = src[i];
		i++;
	}
	dst[i + dlen] = 0;
	return (total);
}

   int main	(int argc, char **argv) 
   {

   size_t n = 0, sz1 = 0; 
   char str[40] = "",
 *s1 = argc > 1 ? argv[1] : "hello", 
 *s2 = argc > 2 ? argv[2] : "world"; 
 printf ("\nconcatenating empty src with\ns1: %s\ns2: %s\n\n", s1, s2);
 sz1 = ft_strlcat (str, s1, 40);
 printf ("after 'strlcat (str, s1, n)', str : %s  (%zu chars)\n", str, sz1);
 n = ft_strlcat (str, s2, 40);     
 printf ("after 'strlcat (str, s2, n)', str : %s  (%zu chars)\n", str, n);
 return (0);
 }

/* Pq e que isto nao da?
   dst[i + dlen] = src[i++];
   --> Qual e a diferença entre a linha acima 
e a de baixo (que funciona no contexto da l.28 ??
   dst[i + dlen] = src[i];
   i++;
 */
