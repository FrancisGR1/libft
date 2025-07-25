/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_destruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:00 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 16:50:00 by frmiguel         ###   ########.fr       */
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

//@TODO: deallocate array of strings
