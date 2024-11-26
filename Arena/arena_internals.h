#ifndef ARENA_INTERNALS_H
# define ARENA_INTERNALS_H

#include "../libft.h"

void _arena_save_ptr(t_dynamic_array *data_ptrs, void *ptr);
void *_arena_lookup_next_ptr(t_arena *arena, void *curr_ptr);
void *_arena_use_reset_chunk(t_arena *arena_list, size_t size_bytes);
t_arena *_arena_of_ptr(t_arena *arena_list, void *ptr);
void _arena_save_reset_chunk(t_arena *arena, void *ptr);

#endif /*ARENA_INTERNALS_H*/
