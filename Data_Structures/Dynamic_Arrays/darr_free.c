/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darr_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:07:03 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:07:03 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_array.h"

void	darr_free(t_dynamic_array *da)
{
	if (!da)
		return ;
	free(da->data);
	free(da);
}

void	darr_free_custom(t_dynamic_array *da, void (*del)(void *data))
{
	size_t	i;
	void	*next_el;

	if (!da)
		return ;
	i = 0;
	if (del != NULL)
	{
		while (i < da->len)
		{
			next_el = da->data + (i * da->data_size);
			del(next_el);
			i++;
		}
	}
	free(da->data);
	free(da);
}
