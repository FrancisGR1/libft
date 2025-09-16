/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:49:59 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:20 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

size_t	str_copy(const t_string *str, char *buffer, size_t pos, size_t len)
{
	size_t	copy_len;

	if (str == NULL || str->data == NULL || buffer == NULL || pos >= str->size)
		return (0);
	copy_len = len;
	if (pos + len > str->size || len == 0)
		copy_len = str->size - pos;
	strncpy(buffer, str->data + pos, copy_len);
	buffer[copy_len] = '\0';
	return (copy_len);
}
