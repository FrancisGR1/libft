#include "libft.h"

size_t array_len(void **arr)
{
	size_t len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}
