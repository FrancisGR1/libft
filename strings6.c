/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:43:31 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:44:04 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	string_put(t_string s, int fd)
{
	if (str_is_null(s))
		return (write(fd, "(null)", 6));
	return (write(fd, s.s, s.len));
}

void	string_free(t_string *str)
{
	if (!str || str_is_null(*str) || str->type != STR_ALLOCATED)
		return ;
	if (str->s)
		free(str->s);
	*str = new_str(NULL, 0);
}

void	string_arr_free(t_string **strs)
{
	t_string	*ptr;

	if (!strs || !*strs)
		return ;
	ptr = *strs;
	while (ptr && !str_is_null(*ptr))
	{
		string_free(ptr);
		ptr++;
	}
	free(*strs);
	*strs = NULL;
}

t_string	*str_arr_dup(t_string *str_arr)
{
	size_t		cnt;
	t_string	*str_arr_dup;

	if (!str_arr)
		return (NULL);
	cnt = 0;
	while (str_arr[cnt].s)
		cnt++;
	str_arr_dup = ft_calloc(cnt + 1, sizeof(t_string));
	cnt = 0;
	while (str_arr[cnt].s)
	{
		str_arr_dup[cnt] = str_dup(str_arr[cnt]);
		cnt++;
	}
	str_arr_dup[cnt] = new_str(NULL, 0);
	return (str_arr_dup);
}

void	str_arr_deep_copy(t_string *dst, t_string *src, int size)
{
	int	i;

	if (!dst || !src || size < 1)
		return ;
	i = 0;
	while (i < size)
	{
		dst[i] = str_dup(src[i]);
		i++;
	}
}
