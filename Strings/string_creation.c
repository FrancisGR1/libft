/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:49:59 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:21 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

t_string	*str_create(const char *str_data)
{
	t_string	*str;

	if (str_data == NULL)
		return (NULL);
	str = malloc(sizeof(t_string));
	if (str == NULL)
		return (NULL);
	str->size = ft_strlen(str_data);
	str->capacity = str->size + STRING_DEFAULT_CAPACITY;
	str->memory = _memory_create(STRING_MEMORY_INITIAL_SIZE);
	if (str->memory == NULL)
	{
		free(str);
		return (NULL);
	}
	str->data = (char *)_region_allocate(str->memory, str->capacity);
	if (str->data == NULL)
	{
		free(str);
		return (NULL);
	}
	ft_strcpy(str->data, str_data);
	return (str);
}

t_string	**str_create_from_multiple(size_t count, ...)
{
	t_string	**strings;
	va_list		args;
	size_t		i;

	if (count <= 0)
		return (NULL);
	va_start(args, count);
	strings = malloc(sizeof(t_string *) * (count + 1));
	if (!strings)
	{
		va_end(args);
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		strings[i] = str_create((const char *)va_arg(args, char *));
		i++;
	}
	strings[count] = NULL;
	va_end(args);
	return (strings);
}
