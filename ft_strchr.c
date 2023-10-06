/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:04:38 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/06 19:04:57 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*(ptr))
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

/*
int main(int c, char **v)
{
	char *str = c > 1 ? v[1] : "What a crazy world";
	char l = c > 2 ? v[2][0] : 'c';
	printf("ft_strchr: %s --> %p\n", ft_strchr(str, l), (void *)ft_strchr(str, l));
	printf("strchr: %s --> %p\n", strchr(str, l), (void *)strchr(str, l));
}
*/
