/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:19:55 by frmiguel          #+#    #+#             */
/*   Updated: 2023/09/10 13:55:50 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
/*
int main(int c, char **v)
{
	char s = c == 2 ? v[1][0] : 'h';
	
	printf("%c\n", ft_toupper(s));
	printf("%c\n", toupper(s));	
	return (0);
}
*
*/
