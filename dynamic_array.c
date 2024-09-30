#include "libft.h"

t_dynamic_array *darr_init(size_t ds)
{
	t_dynamic_array *da;

	da = malloc(sizeof(t_dynamic_array));
	da -> data_size = ds;
	da -> len = 0;
	da -> capacity = DA_INIT_SIZE;
	da -> data = malloc(da->data_size * da->capacity);
	return (da);
}

void darr_append(t_dynamic_array *da, const void *insertion)
{
	size_t new_capacity;
	void *new_data;

	if (da->len >= da->capacity)
	{
		new_capacity = da->capacity += DA_INIT_SIZE;
		new_data = ft_realloc(da->data, new_capacity * da->data_size); 
		da -> data = new_data;
		da -> capacity = new_capacity;
	}
	ft_memcpy((char *)da->data + da->len * da->data_size, insertion, da->data_size);
	da->len++;
}

void darr_free(t_dynamic_array *da)
{
	if (!da)
		return;
	free(da->data);
	free(da);
}

/* Usage example
int main(void)
{
	t_dynamic_array *d = darr_init(sizeof(int));
	for (int i = 0; i < 10; i++)
		darr_append(d, &i);
	for (int i = 0; i < 10; i++)
		ft_fprintf(OUT, "%d\n", ((int *)d->data)[i]);
}
*/
