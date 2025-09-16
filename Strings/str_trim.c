/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_trim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:06 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:29 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

void	str_trim(t_string *str)
{
	if (str == NULL)
		return ;
	str_trim_left(str);
	str_trim_right(str);
}

void	str_trim_left(t_string *str)
{
	size_t	i;

	if (str == NULL || str->size == 0)
		return ;
	i = 0;
	while (i < str->size && ft_isspace((unsigned char)str->data[i]))
	{
		i++;
	}
	if (i > 0)
	{
		ft_memmove(str->data, str->data + i, str->size - i);
		str->size -= i;
		str->data[str->size] = '\0';
	}
}

void	str_trim_right(t_string *str)
{
	int	i;

	if (str == NULL || str->size == 0)
		return ;
	i = str->size;
	while (i > 0 && ft_isspace((unsigned char)str->data[i - 1]))
		i--;
	if (i < (int)str->size)
	{
		str->data[i] = '\0';
		str->size = i;
	}
}

void	str_trim_characters(t_string *str, const char *chars)
{
	char	*start;
	char	*end;
	size_t	new_len;

	if (str == NULL || str->data == NULL || chars == NULL)
		return ;
	start = str->data;
	end = str->data + str->size - 1;
	while (start <= end && ft_strchr(chars, *start))
	{
		start++;
	}
	while (end > start && ft_strchr(chars, *end))
	{
		end--;
	}
	new_len = end - start + 1;
	ft_memmove(str->data, start, new_len);
	str->data[new_len] = '\0';
	str->size = new_len;
}
