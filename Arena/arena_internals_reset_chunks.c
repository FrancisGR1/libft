/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_internals_reset_chunks.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:02:13 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:02:13 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena_internals.h"

void	_arena_move_reset_chunk_ptr(void **reset_chunk_ptr, size_t size_used)
{
	*reset_chunk_ptr += size_used;
}

void	*_arena_reorder_reset_chunk(t_dynamic_array *reset_chunks,
		void *reset_chunk_ptr, size_t size_bytes, size_t size_available)
{
	if (size_available == size_bytes)
		darr_remove(reset_chunks, reset_chunk_ptr);
	if (size_available > size_bytes)
		_arena_move_reset_chunk_ptr(reset_chunk_ptr, size_bytes);
	return (reset_chunk_ptr);
}

void	*_arena_use_reset_chunk(t_arena *arena_list, size_t size_bytes)
{
	size_t	i;
	size_t	size_available;
	void	*data_ptr_after;
	void	*reset_chunk_ptr;

	i = 0;
	while (arena_list)
	{
		while (i < arena_list->reset_chunks->len)
		{
			reset_chunk_ptr = *(void **)((char *)arena_list->reset_chunks->data
					+ i * arena_list->reset_chunks->data_size);
			data_ptr_after = _arena_lookup_next_ptr(arena_list,
					reset_chunk_ptr);
			size_available = data_ptr_after - reset_chunk_ptr;
			if (size_available >= size_bytes)
				return (_arena_reorder_reset_chunk(arena_list->reset_chunks,
						reset_chunk_ptr, size_bytes, size_available));
			i++;
		}
		arena_list = arena_list->next;
	}
	return (NULL);
}
