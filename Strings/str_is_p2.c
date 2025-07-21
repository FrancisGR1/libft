#include "strings.h"

bool str_is_space(const t_string* str)
{
	size_t i;

	if (str == NULL || str->data == NULL)
		return (false);
	i = 0;
	while (str->data[i] != '\0' && ft_isspace(str->data[i]))
	{
		i++;
	}
	return (str->data[i] == '\0');
}

bool str_is_printable(const t_string* str)
{
	size_t i;

	if (str == NULL || str->data == NULL)
		return (false);
	i = 0;
	while (str->data[i] != '\0' && ft_isprint(str->data[i]))
	{
		i++;
	}
	return (str->data[i] == '\0');
}
