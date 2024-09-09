#include "libft.h"

t_da *da_init(size_t ds)
{
	t_da *da;

	da = malloc(sizeof(*da));
	da -> data_size = ds;
	da -> cnt = 0;
	da -> capacity = DA_INIT_SIZE;
	da -> data = malloc(da->capacity * ds);
	return (da);
}

void da_append(t_da *da, const void *insertion)
{
	size_t new_capacity;
	void *new_data;

	if (da->cnt >= da->capacity)
	{
		new_capacity = da->capacity += DA_INIT_SIZE;
		new_data = ft_realloc(da->data, new_capacity * da->data_size); 
		da -> data = new_data;
		da -> capacity = new_capacity;
	}
	ft_memcpy((char *)da->data + da->cnt * da->data_size, insertion, da->data_size);
	da->cnt++;
}

void da_free(t_da *da)
{
	if (!da)
		return;
	free(da->data);
	free(da);
}

