/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:06:25 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:06:25 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

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
