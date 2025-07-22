#include "strings.h"

int str_to_int(const t_string *str)
{
	if (str == NULL)
		return (0);
	if (str_empty(str))
		return (0);
	return (ft_atoi(str->data));
}
