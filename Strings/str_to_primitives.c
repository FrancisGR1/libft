#include "strings.h"

int str_to_int(const t_string *str)
{
	if (str == NULL)
		return (0);
	if (str_empty(str))
		return (0);
	return (ft_atoi(str->data));
}

float str_to_float(const t_string *str)
{
	if (str == NULL)
		return (0);
	if (str_empty(str))
		return (0);
	//@TODO: implementar atof()
	return (atof(str->data));
}

double str_to_double(const t_string* str)
{
	if (str == NULL)
		return (0);
	//@TODO: implementar str_empty()
	if (str_empty(str))
		return (0);
	//@TODO: implementar strtod()
	return (strtod(str->data, NULL));
}
