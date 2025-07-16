#ifndef STRING_INTERNALS_H
# define STRINGS_INTERNALS_H

#include "../libft.h"

typedef struct s_string_memory
{
	//O que é que a memória vai incluir?
	//pointer para a memória
	void *memory;
	size_t size;
	size_t capacity;

} t_string_memory;


//global memory
t_string_memory **_global_memory_ref(void);
bool *_global_memory_is_created_ref(void);
void _init_global_memory(size_t size);
void _destroy_global_memory(void);

//memory management
t_string_memory *_memory_create(size_t capacity);
void *_region_allocate(t_string_memory *region, size_t size);
void _memory_destroy(t_string_memory *memory);



#endif /*STRING_INTERNALS_H*/
