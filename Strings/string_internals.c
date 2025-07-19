#include "string_internals.h"

t_string_memory **_global_memory_ref(void)
{
	static t_string_memory *region;
	return (&region);
}

bool *_global_memory_is_created_ref(void)
{
	static bool memory_is_created;
	return (&memory_is_created);
};

bool _init_global_memory(size_t size)
{
	t_string_memory *created;

	if (*_global_memory_is_created_ref())
	{
		ft_fprintf(STDERR, "Error: Trying to initialize non-null global string memory\n");
		return (false);
	}
	else
	{
		created = _memory_create(size);
		if (created == NULL)
			return (false);
		*_global_memory_ref() = _memory_create(size);
		*_global_memory_is_created_ref() = true;
	}
	return (true);
}

void _destroy_global_memory(void)
{
	t_string_memory *global_region = *_global_memory_ref();

	if (global_region != NULL && *_global_memory_is_created_ref())
	{
		_memory_destroy(global_region);
		*_global_memory_ref() = NULL;
		*_global_memory_is_created_ref() = false;
	}
	else
	{
		ft_fprintf(STDERR, "Error: Trying to free null global string memory\n");
	}


}

//@TODO: mover funcs abaixo para outro ficheiro
t_string_memory *_memory_create(size_t capacity)
{
	t_string_memory *new_region;

	new_region = malloc(sizeof(t_string_memory));
	if (new_region)
	{
		new_region->memory   = malloc(capacity);
		if (new_region->memory == NULL)
		{
			ft_fprintf(STDERR, "Error: allocation for string failed\n");
			free(new_region);
			return (NULL);
		}
		new_region->size     = 0;
		new_region->capacity = capacity;
	}
	else
	{
		ft_fprintf(STDERR, "Error: allocation for t_string_memory failed\n");
		return (NULL);
	}
	return (new_region);
};

void *_region_allocate(t_string_memory *region, size_t size)
{
	void *memory_increment;

	if (region == NULL)
	{
		ft_fprintf(STDERR, "Error: memory region is NULL\n");
		return (NULL);
	}
	if (region->size + size > region->capacity)
	{
		ft_fprintf(STDERR, "Error: memory region out of size. Bytes requested: %d; available: %d\n", size, region->capacity - region->size);
		return (NULL);
	}

	memory_increment = (char *)region->memory + region->size;
	region->size += size;
	return (memory_increment);
};

void _memory_destroy(t_string_memory *region)
{
	if (region == NULL)
	{
		ft_fprintf(STDERR, "Error: attempting to destroy a NULL region\n");
		return ;
	}
	free(region->memory);
	free(region);
};
