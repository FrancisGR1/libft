/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:04 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:27 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

int	str_find(const t_string *str, const char *buffer, size_t pos)
{
	char	*found;
	int		found_pos;

	if (str == NULL || str->data == NULL || buffer == NULL || pos >= str->size)
		return (-1);
	found = ft_strstr(str->data + pos, buffer);
	if (found == NULL)
		return (-1);
	found_pos = (int)(found - str->data);
	return (found_pos);
}

int	str_rfind(const t_string *str, const char *buffer, size_t pos)
{
	size_t	buffer_len;
	int		i;

	if (str == NULL || str->data == NULL || buffer == NULL || pos >= str->size)
		return (-1);
	buffer_len = ft_strlen(buffer);
	if (buffer_len == 0)
		return (-1);
	if (pos < buffer_len - 1)
		return (-1);
	if (pos >= str->size)
		pos = str->size - 1;
	i = (int)pos;
	while (i >= 0)
	{
		if (ft_strncmp(str->data + i, buffer, buffer_len) == 0)
			return (i);
		i--;
	}
	return (-1);
}

int	str_find_first_of(const t_string *str, const char *buffer, size_t pos)
{
	char	*found;

	if (str == NULL || str->data == NULL || buffer == NULL || pos >= str->size)
		return (-1);
	if (pos >= str->size)
		return (-1);
	found = ft_strstr(str->data + pos, buffer);
	if (found != NULL)
		return ((int)(found - str->data));
	return (-1);
}

int	str_find_last_of(const t_string *str, const char *buffer, size_t pos)
{
	char	*current_found;
	int		last_found;

	if (str == NULL || str->data == NULL || buffer == NULL || pos >= str->size)
		return (-1);
	last_found = -1;
	current_found = ft_strstr(str->data, buffer);
	while (current_found != NULL && (size_t)(current_found - str->data) <= pos)
	{
		last_found = (int)(current_found - str->data);
		current_found = ft_strstr(current_found + 1, buffer);
	}
	return (last_found);
}
