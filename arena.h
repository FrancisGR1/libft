#ifndef ARENA_H
# define ARENA_H

#include "libft.h"
//
//Define the default size of allocation
#define ALLOC_SIZE 1024

typedef struct s_arena {
	size_t limit;
	size_t current_size;
	void	*memory;
	void	*end;
	struct s_arena *next;
} t_arena;

t_arena *arena_init(size_t size);
void	*arena_alloc(t_arena **region, size_t nbytes, size_t size);
void arena_destroy(t_arena *arena);
void arena_visualizer(t_arena *region);

#endif /*ARENA_H*/
