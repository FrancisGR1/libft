#include "arena_internals.h"

static int cmp_nums(const void *el1, const void *el2)
{
	return ((long long *)el1 - (long long *)el2);
}

void *_arena_lookup_next_ptr(t_arena *arena, void *curr_ptr)
{
	size_t i;
	t_dynamic_array *data_ptrs;
	void **ptrs_array;

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

void *_arena_use_reset_chunk(t_arena *arena_list, size_t size_bytes)
{
	size_t i;
	size_t size_available;
	void **stored_ptr;
	void *data_ptr_after;
	void *reset_chunk_ptr;

	i = 0;
	while (arena_list)
	{
		while (i < arena_list->reset_chunks->len)
		{
			//TODO:substituir por função auxiliar
			//arena_move_reset_chunk_ptr()
			stored_ptr = (void **)((char*)arena_list->reset_chunks->data + i * arena_list->reset_chunks->data_size);
			reset_chunk_ptr = *stored_ptr;
			data_ptr_after = _arena_lookup_next_ptr(arena_list, reset_chunk_ptr);
			size_available = data_ptr_after - reset_chunk_ptr;
			if (size_available >= size_bytes)
			{
				darr_remove(arena_list->reset_chunks, reset_chunk_ptr);
				return (reset_chunk_ptr);
			}
			i++;
		}
		arena_list = arena_list -> next;
	}
	return (NULL);
}

t_arena *_arena_of_ptr(t_arena *arena_list, void *ptr)
{
	t_arena *arena_of_ptr;

	if (!arena_list || !ptr)
		return (NULL);
	arena_of_ptr = arena_list;
	while (arena_of_ptr && (ptr < arena_of_ptr->memory || ptr > arena_of_ptr->end))
		arena_of_ptr = arena_of_ptr->next;
	return (arena_of_ptr);
}

void _arena_save_ptr(t_dynamic_array *data_ptrs, void *ptr)
{
	darr_append(data_ptrs, &ptr);
	darr_sort(data_ptrs, cmp_nums);
}
