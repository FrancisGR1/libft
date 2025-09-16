/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:05 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:28 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

t_string	*str_substr(t_string *str, size_t pos, size_t len)
{
	t_string	*substr;

	if (str == NULL || pos >= str->size)
		return (NULL);
	if (pos + len > str->size)
		len = str->size - pos;
	substr = str_create("");
	substr->size = len;
	substr->capacity = len + 1;
	substr->data = malloc(substr->capacity * sizeof(char));
	if (substr->data == NULL)
	{
		free(substr);
		return (NULL);
	}
	ft_strncpy(substr->data, str->data + pos, len);
	substr->data[len] = '\0';
	return (substr);
}

size_t	str_count(const t_string *str, const char *substr)
{
	size_t			count;
	const char		*tmp;
	const char		*found;
	const size_t	substr_len = ft_strlen(substr);

	if (str == NULL || substr == NULL || str->data == NULL
		|| str_empty(str) == true || substr_len == 0)
		return (0);
	tmp = str->data;
	count = 0;
	while (true)
	{
		found = ft_strstr(tmp, substr);
		if (found == NULL)
			break ;
		count++;
		tmp = found + substr_len;
	}
	return (count);
}
