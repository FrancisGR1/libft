/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:43:31 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:44:03 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safer_strings.h"

int	string_find(t_string str, size_t start, size_t n, char *delimiters)
{
	const t_string	delims_ptr = cstr_to_str_ptr(delimiters,
			ft_strlen(delimiters));
	size_t			i;

	if (str_is_null(str) || str_is_null(delims_ptr))
		return (-1);
	while (start < str.len && n--)
	{
		i = 0;
		while (i < delims_ptr.len)
		{
			if (str.s[start] == delims_ptr.s[i])
				return (start);
			i++;
		}
		start++;
	}
	return (-1);
}

t_string	string_find_word(t_string str, size_t start, t_string target)
{
	t_string	res;

	res = new_str(NULL, 0);
	if (str_is_null(str) || str_is_null(target))
		return (res);
	while (start < str.len)
	{
		if (str_cmp(str, target, start) == 0)
		{
			res = cstr_to_str_ptr(&str.s[start], target.len);
			break ;
		}
		start++;
	}
	return (res);
}

struct s_dynamic_array *string_findall(t_string str, char *delimiters)
{
	const t_string	delims_ptr = cstr_to_str_ptr(delimiters,
			ft_strlen(delimiters));
	t_dynamic_array	*ptrs;
	int				i;
	size_t			j;
	t_string		s;

	ptrs = darr_init(sizeof(t_string));
	i = -1;
	while (++i < (int)str.len)
	{
		j = -1;
		while (++j < delims_ptr.len)
		{
			s = cstr_to_str_ptr(&str.s[i], 1);
			if (str.s[i] == delims_ptr.s[j])
				darr_append(ptrs, (const void *)&s);
		}
	}
	if (!ptrs->len)
	{
		darr_free(ptrs);
		ptrs = NULL;
	}
	return (ptrs);
}

