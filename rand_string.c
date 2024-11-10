/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:19:04 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:19:04 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*rand_string(void)
{
	static char	rs[20];
	int			i;

	i = 0;
	while (i < 20)
		rs[i++] = ft_rand() % 25 + 97;
	rs[i] = '\0';
	return (rs);
}
