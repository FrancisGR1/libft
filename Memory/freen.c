/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:18:51 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:18:51 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	freen(void **data)
{
	if (!data || !*data)
		return ;
	free(*data);
	*data = NULL;
}

//TODO: mudar estas 2 funcs de sítio
void	freen_arr(void **data)
{
	size_t	idx;

	idx = 0;
	if (!data)
		return ;
	if (!*data)
		return ;
	while (data[idx])
	{
		freen(&data[idx]);
		idx++;
	}
	free(data);
}

void	freen_arr_with_custom_func(void **data, void (*del)(void *))
{
	size_t	idx;

	idx = 0;
	if (!data)
		return ;
	if (!*data)
		return ;
	while (data[idx])
	{
		del(&data[idx]);
		idx++;
	}
	free(data);
}
