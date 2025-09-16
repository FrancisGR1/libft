/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:01 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:23 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

void	str_append(t_string *str, const char *cstr_to_append)
{
	size_t	cstr_size;
	size_t	new_size;
	char	*new_data;

	if (str == NULL || cstr_to_append == NULL)
		return ;
	cstr_size = ft_strlen(cstr_to_append);
	if (cstr_size == 0)
		return ;
	if (str->size + cstr_size >= str->capacity)
	{
		new_size = str->size + cstr_size + 1;
		new_data = _region_allocate(str->memory, new_size);
		if (!new_data)
			return ;
		ft_memcpy(new_data, str->data, str->size);
		str->data = new_data;
		str->capacity = new_size;
	}
	ft_strcpy(str->data + str->size, cstr_to_append);
	str->size += cstr_size;
}

void	str_push_back(t_string *str, const char ch_to_push)
{
	size_t	new_capacity;
	char	*new_data;

	if (str == NULL)
		return ;
	if (str->size + 1 >= str->capacity)
	{
		new_capacity = str->capacity * 2;
		new_data = _region_allocate(str->memory, new_capacity);
		if (!new_data)
			return ;
		ft_memcpy(new_data, str->data, str->size);
		str->data = new_data;
		str->capacity = new_capacity;
	}
	str->data[str->size] = ch_to_push;
	str->size++;
	str->data[str->size] = '\0';
}

void	str_insert(t_string *str, size_t pos, const char *insertion)
{
	const size_t	insertion_len = ft_strlen(insertion);
	size_t			total_len;
	size_t			new_capacity;
	char			*new_data;

	if (str == NULL || insertion == NULL || pos > str->size)
		return ;
	total_len = insertion_len + str->size;
	if (total_len + 1 > str->capacity)
	{
		new_capacity = total_len + 1;
		new_data = _region_allocate(str->memory, new_capacity);
		ft_memcpy(new_data, str->data, pos);
		ft_memcpy(new_data + pos + insertion_len, str->data + pos, str->size
			- pos);
		str->data = new_data;
		str->capacity = new_capacity;
	}
	else
		ft_memmove(str->data + pos + insertion_len, str->data + pos, str->size
			- pos);
	ft_memcpy(str->data + pos, insertion, insertion_len);
	str->size = total_len;
}

void	str_assign(t_string *str, const char *new_str)
{
	size_t	new_str_len;
	char	*new_data;

	if (str == NULL || new_str == NULL)
		return ;
	new_str_len = ft_strlen(new_str);
	if (new_str_len + 1 > str->capacity)
	{
		new_data = (char *)_region_allocate(str->memory, new_str_len + 1);
		if (new_data == NULL)
			return ;
		str->data = new_data;
		str->capacity = new_str_len + 1;
	}
	ft_strcpy(str->data, new_str);
	str->size = new_str_len;
}
