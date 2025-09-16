/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:03 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:26 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

static void	str_replace_util(t_string *str, const char *old_str,
				const char *new_str, char *pos);

void	str_replace(t_string *str, const char *old_str, const char *new_str)
{
	char	*pos;

	if (str == NULL || old_str == NULL || new_str == NULL)
		return ;
	pos = ft_strstr(str->data, old_str);
	if (pos == NULL)
		return ;
	str_replace_util(str, old_str, new_str, pos);
}

void	str_replace_all(t_string *str, const char *old_str, const char *new_str)
{
	t_string	*tmp;
	char		*start;
	char		*end;

	if (str == NULL || old_str == NULL || new_str == NULL)
		return ;
	tmp = str_create("");
	if (tmp == NULL)
		return ;
	start = str->data;
	while (true)
	{
		end = ft_strstr(start, old_str);
		if (!end)
			break ;
		*end = '\0';
		str_append(tmp, start);
		str_append(tmp, new_str);
		start = end + ft_strlen(old_str);
	}
	str_append(tmp, start);
	str_assign(str, tmp->data);
	str_deallocate(tmp);
}

static void	str_replace_util(t_string *str, const char *old_str,
		const char *new_str, char *pos)
{
	const size_t	old_len = ft_strlen(old_str);
	const size_t	new_len = ft_strlen(new_str);
	size_t			tail_len;
	size_t			new_size;
	char			*new_data;

	if (str == NULL || old_str == NULL || new_str == NULL || pos == NULL)
		return ;
	tail_len = ft_strlen(pos + old_len);
	new_size = (pos - str->data) + new_len + tail_len;
	if (new_size + 1 > str->capacity)
	{
		new_data = (char *)_region_allocate(str->memory, new_size + 1);
		ft_memcpy(new_data, str->data, pos - str->data);
		ft_memcpy(new_data + (pos - str->data) + new_len, pos + old_len,
			tail_len);
		str->data = new_data;
		str->capacity = new_size + 1;
	}
	else
		ft_memmove(pos + new_len, pos + old_len, tail_len);
	ft_memcpy(pos, new_str, new_len);
	str->data[new_size] = '\0';
	str->size = new_size;
}
