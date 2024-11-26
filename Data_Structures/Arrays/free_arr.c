#include "array.h"

void	freen_arr(void **data)
{
	size_t	idx;

	idx = 0;
	if (!data)
		return ;
	if (!*data)
		return ;
	while (data[idx])
	{
		freen(&data[idx]);
		idx++;
	}
	free(data);
}

void	freen_arr_with_custom_func(void **data, void (*del)(void *))
{
	size_t	idx;

	idx = 0;
	if (!data)
		return ;
	if (!*data)
		return ;
	while (data[idx])
	{
		del(&data[idx]);
		idx++;
	}
	free(data);
}
