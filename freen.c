#include "libft.h"

void freen(void **data)
{
	if (!data || !*data)
		return ;
	free(*data);
}
