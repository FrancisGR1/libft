/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:15:19 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:15:19 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	swap_bytes(void *el1, void *el2, size_t data_size)
{
	unsigned char	*tmp;
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	if (!el1 || !el2)
		return ;
	a = el1;
	b = el2;
	i = 0;
	tmp = 0;
	while (i < data_size)
	{
		*tmp = a[i];
		a[i] = b[i];
		b[i] = *tmp;
		i++;
	}
}
