/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:38:15 by francis           #+#    #+#             */
/*   Updated: 2025/07/22 17:03:24 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	if (!n && ft_strlen(little) != 0)
		return (0);
	if (ft_strncmp(little, "", n) == 0 || *little == '\0')
		return ((char *)big);
	j = 0;
	while (*big && j < n)
	{
		i = 0;
		while (big[i] && big[i] == little[i] && little[i] && (j + i) < n)
		{
			if (!little[i + 1])
				return ((char *)big);
			i++;
		}
		big++;
		j++;
	}
	return (0);
}
/*   int main (int c, char **v)
   {
   char *str1 = c > 1 ? v[1] : "Hello Crazy World";
   char *str2 = c > 2 ? v[2] : "Crazy";
   size_t n = c > 3 ? atoi(v[3]) : 20;
//char *word = strnstr(str1, str1, n);
printf("%s\n", ft_strnstr(str1, str1, n));
//printf("%s\n", word);
}
*/
