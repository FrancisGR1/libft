/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:04:38 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:19 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	while (*ptr != (char)c)
	{
		if (*ptr == 0)
			return (0);
		ptr++;
	}
	return (ptr);
}
/*
   int main(int c, char **v)
   {
   char *str = c > 1 ? v[1] : "\0";
   char l =  c > '2' ? v[2][0] : 0;
   printf("ft_strchr: %s --> %p\n",
   ft_strchr(str, l), (void *)ft_strchr(str, l));
   printf("strchr: %s --> %p\n", strchr(str, l), (void *)strchr(str, l));
   }
*/
