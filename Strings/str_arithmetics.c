#include "strings.h"

bool str_is_equal(const t_string* str1, const t_string* str2)
{
	return (str_compare(str1, str2) == 0);
}

bool str_is_not_equal(const t_string* str1, const t_string* str2)
{
	return (str_compare(str1, str2) != 0);
}

bool str_is_less(const t_string* str1, const t_string* str2)
{
	return (str_compare(str1, str2) < 0);
}

bool str_is_greater(const t_string* str1, const t_string* str2)
{
	return (str_compare(str1, str2) > 0);
}
