#include "strings.h"

size_t str_length(const t_string* str)
{
	if (str == NULL)
		return (0);
	return (str->size);
}

size_t str_capacity(const t_string* str)
{
	if (str == NULL)
		return (0);
	return (str->capacity);
}

size_t str_max_size(void)
{
	return (MAX_STRING_SIZE);
}

bool str_empty(const t_string* str)
{
	return (str == NULL || str->size == 0);
}
