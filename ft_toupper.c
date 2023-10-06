/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:02:46 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/06 19:02:47 by frmiguel         ###   ########.fr       */
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
