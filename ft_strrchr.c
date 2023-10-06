/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:05:28 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/06 19:06:15 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*location;

	ptr = (char *)s;
	location = 0;
	while (*ptr)
	{
		if (*ptr == c)
			location = ptr;
		ptr++;
	}
	if (!location)
		return (0);
	else
		return (location);
}
/*
int	main(int c, char **v)
{
	char *str = c > 1 ? v[1] : "helloolatdbem";
	char l = c > 2 ? v[2][0] : 'o';  
	printf("%s --> %p\n", ft_strrchr(str, l), ft_strrchr(str,l));
	printf("%s --> %p\n", strrchr(str, l), strrchr(str,l)); 
}
*/
