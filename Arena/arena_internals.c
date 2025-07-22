/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_internals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:02:12 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:02:12 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena_internals.h"

static int	cmp_nums(const void *el1, const void *el2)
{
	return ((long long *)el1 - (long long *)el2);
}

void	*_arena_lookup_next_ptr(t_arena *arena, void *curr_ptr)
{
	size_t			i;
	t_dynamic_array	*data_ptrs;
	void			**ptrs_array;

	i = 0;
	data_ptrs = arena->data_ptrs;
	ptrs_array = data_ptrs->data;
	while (i < data_ptrs->len)
	{
		if (curr_ptr < ptrs_array[i])
			return (ptrs_array[i]);
		i++;
	}
	return (arena->end);
}

t_arena	*_arena_of_ptr(t_arena *arena_list, void *ptr)
{
	t_arena	*arena_of_ptr;

	if (!arena_list || !ptr)
		return (NULL);
	arena_of_ptr = arena_list;
	while (arena_of_ptr && (ptr < arena_of_ptr->memory
			|| ptr > arena_of_ptr->end))
		arena_of_ptr = arena_of_ptr->next;
	return (arena_of_ptr);
}

void	_arena_save_ptr(t_dynamic_array *to_save, void *ptr)
{
	darr_append(to_save, &ptr);
	darr_sort(to_save, cmp_nums);
}
