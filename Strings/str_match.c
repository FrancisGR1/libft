/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_match.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:03 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:25 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

bool	str_contains(const t_string *str, const char *substr)
{
	return (str != NULL && substr != NULL && ft_strstr(str->data,
			substr) != NULL);
}

bool	str_starts_with(const t_string *str, const char *substr)
{
	size_t	substr_len;

	if (str == NULL || str->data == NULL || substr == NULL)
		return (false);
	substr_len = ft_strlen(substr);
	if (substr_len > str->size)
		return (false);
	return (ft_strncmp(str->data, substr, substr_len) == 0);
}

bool	str_ends_with(const t_string *str, const char *substr)
{
	size_t	substr_len;

	if (str == NULL || str->data == NULL || substr == NULL)
		return (false);
	substr_len = ft_strlen(substr);
	if (substr_len > str->size)
		return (false);
	return (ft_strncmp(str->data + str->size - substr_len, substr,
			substr_len) == 0);
}
