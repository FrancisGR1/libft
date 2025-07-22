#include "strings.h"

t_string *str_from_int(int value)
{
	const char *buffer = ft_itoa(value);
	t_string *converted;

	converted = str_create(buffer);
	free((char *)buffer);
	return (converted);
}
