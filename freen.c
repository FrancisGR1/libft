#include "libft.h"

void freen(void **data)
{
	if (!data || !*data)
		return ;
	free(*data);
	*data = NULL;
}

void freen_arr(void **data)
{
	size_t idx;

	idx = 0;
	if (!data || !*data)
		return ;
	while (data[idx])
	{
		freen(&data[idx]);
		idx++;
	}
	free(data);
}
