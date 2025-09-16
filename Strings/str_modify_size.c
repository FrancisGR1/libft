/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_modify_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:03 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:25 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

void	str_resize(t_string *str, size_t new_size)
{
	size_t	new_capacity;
	char	*new_data;

	if (str == NULL || str->data == NULL)
		return ;
	if (new_size < str->size)
	{
		str->size = new_size;
		str->data[new_size] = '\0';
	}
	else if (new_size > str->size)
	{
		if (new_size >= str->capacity)
		{
			new_capacity = new_size + 1;
			new_data = (char *)_region_allocate(str->memory, new_capacity);
			ft_memcpy(new_data, str->data, str->size);
			str->data = new_data;
			str->capacity = new_capacity;
		}
		ft_memset(str->data + str->size, '\0', new_size - str->size);
		str->size = new_size;
	}
}

void	str_reserve(t_string *str, size_t new_capacity)
{
	char	*data_dup;

	if (str == NULL)
		return ;
	if (new_capacity > str->capacity)
	{
		data_dup = ft_strndup(str->data, str->size);
		_memory_destroy(str->memory);
		str->capacity = new_capacity;
		str->memory = _memory_create(str->capacity);
		str->data = (char *)_region_allocate(str->memory, str->size);
		ft_memcpy(str->data, data_dup, str->size);
		str->data[str->size] = '\0';
		free(data_dup);
	}
}

void	str_shrink_to_fit(t_string *str)
{
	size_t	new_capacity;
	char	*new_data;

	if (str == NULL || str->size + 1 == str->capacity || str->data == NULL)
		return ;
	new_capacity = str->size + 1;
	new_data = (char *)_region_allocate(str->memory, new_capacity);
	if (new_data == NULL)
		return ;
	ft_memcpy(new_data, str->data, str->size);
	new_data[str->size] = '\0';
	str->data = new_data;
	str->capacity = new_capacity;
}

bool	str_set_memory_size(t_string *str, size_t new_size)
{
	char		*new_data;
	const char	*data_dup;

	if (str == NULL || new_size == 0)
		return (false);
	data_dup = ft_strndup(str->data, str->size);
	if (str->memory)
	{
		_memory_destroy(str->memory);
		str->memory = NULL;
	}
	str->memory = _memory_create(new_size);
	if (str->memory && str->size > 0 && str->data)
	{
		new_data = (char *)_region_allocate(str->memory, str->size + 1);
		ft_memcpy(new_data, data_dup, str->size);
		new_data[str->size] = '\0';
		str->data = new_data;
	}
	free((char *)data_dup);
	return (true);
}
