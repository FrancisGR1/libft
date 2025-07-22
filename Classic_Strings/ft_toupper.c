/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:02:46 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:26 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
/*
int	main(int c, char **v)
{
	char	s;

	s = c == 2 ? v[1][0] : 'h';
	printf("%c\n", ft_toupper(s));
	printf("%c\n", toupper(s));
	return (0);
}
*
*/
