/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:38:15 by francis           #+#    #+#             */
/*   Updated: 2023/10/06 19:21:42 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char			*ptr_s1;
	char			*ptr_s2;
	size_t			s2_len;
	unsigned long	i;
	unsigned long	j;

	ptr_s1 = (char *)s1;
	ptr_s2 = (char *)s2;
	s2_len = ft_strlen(s2);
	i = 0;
	if (ptr_s2 == "")
		return (ptr_s1);
	while (*ptr_s1 && n)
	{
		j = 0;
		while (ptr_s1[i + j] == ptr_s2[j] && ptr_s2[j++])
			;
		if (j == s2_len)
			return (&ptr_s1[i]);
		i++;
		n--;
	}
	return (0);
}
/*
   int main (int c, char **v)
   {
   char *str1 = c > 1 ? v[1] : "Hello Crazy World";
   char *str2 = c > 2 ? v[2] : "Crazy";
   size_t n = c > 3 ? atoi(v[3]) : 7;

   printf("%s\n", ft_strnstr(str1, str2, n));
   }
 */
