#include "strings.h"

int str_find_first_not_of(const t_string* str, const char* buffer, size_t pos)
{
	size_t buffer_len;
	size_t i;

	if (str == NULL || str->data == NULL || buffer == NULL || pos >= str->size)
		return (-1);
	buffer_len = ft_strlen(buffer);
	if (buffer_len == 0)
		return (-1);
	i = 0;
	while (i < str->size)
	{
		if (ft_strchr(buffer, str->data[i]) == NULL)
		{
			return ((int)i);
		}
		i++;
	}
	return (-1);

}

int str_find_last_not_of(const t_string* str, const char* buffer, size_t pos)
{
	size_t buffer_len;
	int i;

	if (str == NULL || str->data == NULL || buffer == NULL || pos >= str->size)
		return (-1);
	buffer_len = ft_strlen(buffer);
	if (buffer_len == 0)
		return (-1);
	if (pos >= str->size)
		pos = (int)(str->size - 1);
	i = pos;
	while (i >= 0)
	{
		if (ft_strchr(buffer, str->data[i]) == NULL)
		{
			return ((int)i);
		}
		i--;
	}
	return (-1);
}
