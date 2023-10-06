/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:42:56 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/06 17:42:59 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
		return (1024);
	else
		return (0);
}
/*
int main(int c, char **v)
{
   int  mine = ft_isalpha(atoi(v[1]));
   int std = isalpha(atoi(v[1]));

   printf("%d\n%d\n", mine, std);
}
*/
