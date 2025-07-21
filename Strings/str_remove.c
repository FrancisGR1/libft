#include "strings.h"

void str_erase(t_string* str, size_t pos, size_t len)
{
	if (str == NULL || str->data == NULL || pos >= str->size)
		return ;
	if (pos + len > str->size)
		len = str->size - pos;
	ft_memmove(str->data + pos, str->data + pos + len, str->size - pos - len + 1);
	str->size -= len;
}

void str_pop_back(t_string* str)
{
	if (str == NULL || str->data == NULL || str->size == 0)
		return ;
	str->data[str->size - 1] = '\0';
	str->size--;
}

void str_remove(t_string* str, const char* substr)
{
	size_t len;
	char *data;

	if (str == NULL || str->data == NULL || str->size == 0 || substr == NULL)
		return ;
	len = ft_strlen(substr);
	if (len == 0)
		return ;
	data = str->data;
	while (true)
	{
		if (data == NULL)
			break ;
		ft_memmove(data, data + len, ft_strlen(data + len) + 1);
	}

}

void str_remove_range(t_string* str, size_t start_pos, size_t end_pos)
{
	size_t len;

	if (str == NULL || str->data == NULL || str->size == 0)
		return ;
	if (start_pos >= end_pos || end_pos > str->size)
		return ;
	len = end_pos - start_pos;
	ft_memmove(str->data + start_pos, str->data + end_pos, str->size - end_pos + 1);
	str->size -= len;
}
