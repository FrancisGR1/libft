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

#include "libft.h"

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

// delimiters are chars
t_string	*string_split(t_string str, char *delimiters, int *len)
{
	const t_string	delims_ptr = cstr_to_str_ptr(delimiters,
			ft_strlen(delimiters));
	t_string		*strs;
	size_t			idx;
	size_t			start;

	strs = malloc((word_ncount(str.s, delims_ptr.s, str.len) + 1)
			* sizeof(t_string));
	idx = -1;
	*len = 0;
	start = 0;
	while (++idx < str.len)
	{
		while (idx < str.len && string_find(str, idx, 1, delims_ptr.s) != -1)
			idx++;
		start = idx;
		while (idx < str.len && string_find(str, idx, 1, delims_ptr.s) == -1)
			idx++;
		if (idx > start)
			strs[(*len)++] = cstr_to_str_ptr(str.s + start, idx - start);
	}
	if (!*len)
		return (free(strs), NULL);
	strs[*len] = new_str(NULL, 0);
	return (strs);
}

t_string	*string_split_dup(t_string str, char *delimiters, int *len)
{
	const t_string	delims_ptr = cstr_to_str_ptr(delimiters,
			ft_strlen(delimiters));
	t_string		*strs;
	int				i;
	size_t			start;

	strs = malloc((word_ncount(str.s, delims_ptr.s, str.len) + 1)
			* sizeof(t_string));
	i = -1;
	*len = 0;
	start = 0;
	while (++i < (int) str.len)
	{
		while (i < (int)str.len && string_find(str, i, 1, delims_ptr.s) != -1)
			i++;
		start = i;
		while (i < (int)str.len && string_find(str, i, 1, delims_ptr.s) == -1)
			i++;
		if (i > (int)start)
			strs[(*len)++] = str_dup(cstr_to_str_ptr(str.s + start, i
						- start));
	}
	if (!*len)
		return (free(strs), NULL);
	return (strs[*len] = new_str(NULL, 0), strs);
}

size_t	strs_count(t_string *args)
{
	size_t	i;

	if (!args)
		return (0);
	i = 0;
	while (args[i].s)
		i++;
	return (i);
}
