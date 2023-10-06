/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:58:14 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/06 17:48:44 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
int main(int c, char **v)
{
	int mine = ft_isascii(atoi(v[1]));
	int std = isascii(atoi(v[1]));
	
	printf("%d\n", mine);
	printf("%d\n", std);
}
*/
