#include "libft.h"

void freen(void *data)
{
	void **ptr;

	if (!data)
		return;
	ptr = (void **)data;
	free(*ptr);
	*ptr = NULL;
}
