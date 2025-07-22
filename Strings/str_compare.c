#include "strings.h"

int str_compare(const t_string* str1, const t_string* str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		if (str1 == str2)
			return (0);
		if (str1 == NULL)
			return (-1);
		if (str2 == NULL)
			return (1);
	}
	return (ft_strcmp(str1->data, str2->data));
}

int str_compare_ignore_case(const t_string* str1, const t_string* str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		if (str1 == str2)
			return (0);
		if (str1 == NULL)
			return (-1);
		if (str2 == NULL)
			return (1);
	}
	return (ft_strcasecmp(str1->data, str2->data));
}
