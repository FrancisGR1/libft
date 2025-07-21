#ifndef STRING_INTERNALS_H
# define STRINGS_INTERNALS_H

#include "../libft.h"

typedef struct s_string_memory
{
	void *memory;
	size_t size;
	size_t capacity;

} t_string_memory;

//memory management
t_string_memory *_memory_create(size_t capacity);
void *_region_allocate(t_string_memory *region, size_t size);
void _memory_destroy(t_string_memory *memory);

#endif /*STRING_INTERNALS_H*/
