#include "libft.h"

void *ft_realloc(void *data, size_t data_size)
{
	void *new;

	new = malloc(data_size);
	ft_memcpy(new, data, data_size);
	if (data != NULL)
		free(data);
	return new;
}
