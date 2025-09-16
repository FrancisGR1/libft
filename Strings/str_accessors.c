/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_accessors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:49:58 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:18 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	str_at(const t_string *str, size_t index)
{
	if (str == NULL || str->data == NULL || index >= str->size)
		return ('\0');
	return (str->data[index]);
}

const char	*str_c_str(const t_string *str)
{
	if (str == NULL || str->data == NULL)
		return (NULL);
	return ((const char *)str->data);
}

char	*str_end(const t_string *str)
{
	if (str == NULL || str->data == NULL)
		return (NULL);
	if (str->size == 0)
		return ((char *)str->data);
	return ((char *)&str->data[str->size - 1]);
}

char	*str_begin(const t_string *str)
{
	if (str == NULL || str->data == NULL)
		return (NULL);
	return (str->data);
}
