/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:05:28 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:24 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
/*   int	main(int c, char **v)
   {
   char *str = c > 1 ? v[1] : "helloolatdbem";
   char l = c > 2 ? v[2][0] : '\0';
   printf("%s --> %p\n", ft_strrchr(str, l), ft_strrchr(str,l));
   printf("%s --> %p\n", strrchr(str, l), strrchr(str,l));
   }
*/
