/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:03 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:26 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

void	str_erase(t_string *str, size_t pos, size_t len)
{
	if (str == NULL || str->data == NULL || pos >= str->size)
		return ;
	if (pos + len > str->size)
		len = str->size - pos;
	ft_memmove(str->data + pos, str->data + pos + len, str->size - pos - len
		+ 1);
	str->size -= len;
}

void	str_erase_if(t_string *str, int (*should_remove)(int c),
		size_t start_at)
{
	size_t	i;
	size_t	write_pos;

	if (str == NULL || str->data == NULL || should_remove == NULL
		|| start_at >= str->size)
		return ;
	write_pos = start_at;
	i = start_at;
	while (i < str->size)
	{
		if (should_remove(str->data[i]) != 0)
			;
		else
		{
			str->data[write_pos] = str->data[i];
			write_pos++;
		}
		i++;
	}
	str->data[write_pos] = '\0';
	str->size = write_pos;
}

void	str_pop_back(t_string *str)
{
	if (str == NULL || str->data == NULL || str->size == 0)
		return ;
	str->data[str->size - 1] = '\0';
	str->size--;
}

void	str_remove(t_string *str, const char *substr)
{
	size_t	substr_len;
	char	*data;
	char	*substr_pos;
	size_t	remaining_len;

	if (str == NULL || str->data == NULL || str->size == 0 || substr == NULL)
		return ;
	substr_len = ft_strlen(substr);
	if (substr_len == 0)
		return ;
	data = str->data;
	substr_pos = ft_strstr(data, substr);
	if (substr_pos == NULL)
		return ;
	remaining_len = ft_strlen(substr_pos + substr_len);
	ft_memmove(substr_pos, substr_pos + substr_len, remaining_len + 1);
	str->size -= substr_len;
}

void	str_remove_range(t_string *str, size_t start_pos, size_t end_pos)
{
	size_t	len;

	if (str == NULL || str->data == NULL || str->size == 0)
		return ;
	if (start_pos >= end_pos || end_pos > str->size)
		return ;
	len = end_pos - start_pos;
	ft_memmove(str->data + start_pos, str->data + end_pos, str->size - end_pos
		+ 1);
	str->size -= len;
}
