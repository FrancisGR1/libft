#include "strings.h"

size_t str_copy(const t_string *str, char *buffer, size_t pos, size_t len)
{
	size_t copy_len;

	if (str == NULL || str->data == NULL || buffer == NULL
			|| pos >= str->size)
		return (0);
	copy_len = len;
	if (pos + len > str->size || len == 0)
		copy_len = str->size - pos;
	//@TODO: implementar ft_strncpy
	strncpy(buffer, str->data + pos, copy_len);
	buffer[copy_len] = '\0';
	return (copy_len);
}
