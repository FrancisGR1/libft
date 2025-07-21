#include "strings.h"

bool str_is_alpha(const t_string* str)
{
	size_t i;

	if (str == NULL || str->data == NULL)
		return (false);
	i = 0;
	while (str->data[i] != '\0' && ft_isalpha(str->data[i]))
	{
		i++;
	}
	return (str->data[i] == '\0');
}

bool str_is_digit(const t_string* str)
{
	size_t i;

	if (str == NULL || str->data == NULL)
		return (false);
	i = 0;
	while (str->data[i] != '\0' && ft_isdigit(str->data[i]))
	{
		i++;
	}
	return (str->data[i] == '\0');
}

bool str_is_alnum(const t_string* str)
{
	size_t i;

	if (str == NULL || str->data == NULL)
		return (false);
	i = 0;
	while (str->data[i] != '\0' && ft_isalnum(str->data[i]))
	{
		i++;
	}
	return (str->data[i] == '\0');

}

bool str_is_lower(const t_string* str)
{
	size_t i;

	if (str == NULL || str->data == NULL)
		return (false);
	i = 0;
	//@TODO: implementar islower()
	while (str->data[i] != '\0' && islower(str->data[i]))
	{
		i++;
	}
	return (str->data[i] == '\0');
}

bool str_is_upper(const t_string* str)
{
	size_t i;

	if (str == NULL || str->data == NULL)
		return (false);
	i = 0;
	//@TODO: implementar isupper()
	while (str->data[i] != '\0' && isupper(str->data[i]))
	{
		i++;
	}
	return (str->data[i] == '\0');
}
