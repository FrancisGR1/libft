/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:04 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:28 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

size_t	str_length(const t_string *str)
{
	if (str == NULL)
		return (0);
	return (str->size);
}

size_t	str_capacity(const t_string *str)
{
	if (str == NULL)
		return (0);
	return (str->capacity);
}

size_t	str_max_size(void)
{
	return (SIZE_MAX);
}

bool	str_empty(const t_string *str)
{
	return (str == NULL || str->size == 0);
}
