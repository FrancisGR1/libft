#include "strings.h"

bool str_deallocate(t_string *str)
{
	if (str == NULL)
	{
		return (false);
	}
	_memory_destroy(str->memory);
	if (str->memory != NULL)
		str->memory = NULL;
	//if (*_global_memory_is_created_ref() == true)
	//	_destroy_global_memory();
	free(str);
	return (true);
};

bool str_clear(t_string* str)
{
	if (str == NULL)
		return (false);
	if (str->memory == NULL)
		return (false);
	str->size = 0;
	if (str->data != NULL)
		str->data[0] = '\0';
	return (true);
}
