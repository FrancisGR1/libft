/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:44:13 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/06 17:46:29 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	else
		return (0);
}
/*
int main(int c, char **v)
{
	int mine = ft_isdigit(atoi(v[1]));
	int std = isdigit(atoi(v[1]));
	
	printf("%d\n%d\n", mine, std);	
}
*/
