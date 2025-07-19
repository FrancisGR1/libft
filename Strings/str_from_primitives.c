#include "strings.h"

t_string *str_from_int(int value)
{
	char buffer[12];
	t_string *converted;
	//@TODO: implementar ft_snprintf
	snprintf(buffer, sizeof(buffer), "%d", value);
	converted = str_create(buffer);
	return (converted);
}

t_string *str_from_float(float value)
{
	char buffer[32];
	t_string *converted;
	//@TODO: implementar ft_snprintf
	snprintf(buffer, sizeof(buffer), "%f", value);
	converted = str_create(buffer);
	return (converted);
}

t_string *str_from_double(double value)
{
	char buffer[32];
	t_string *converted;
	//@TODO: implementar ft_snprintf
	snprintf(buffer, sizeof(buffer), "%f", value);
	converted = str_create(buffer);
	return (converted);
}
