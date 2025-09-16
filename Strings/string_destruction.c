/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_destruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:00 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:21 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

bool	str_deallocate(t_string *str)
{
	if (str == NULL)
	{
		return (false);
	}
	_memory_destroy(str->memory);
	if (str->memory != NULL)
		str->memory = NULL;
	free(str);
	return (true);
}

bool	str_clear(t_string *str)
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

bool	str_array_deallocate(t_string **arr_of_strs, size_t count)
{
	size_t	i;

	if (arr_of_strs == NULL || count == 0)
		return (false);
	i = 0;
	while (i < count)
	{
		if (arr_of_strs[i] != NULL)
			str_deallocate(arr_of_strs[i]);
		i++;
	}
	free(arr_of_strs);
	return (true);
}

void	str_deallocate_interface(void *ptr)
{
	if (ptr != NULL)
	{
		str_deallocate((t_string *)ptr);
	}
}
