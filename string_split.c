/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:43:31 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:44:04 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safer_strings.h"

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

// delimiter is a word
t_string	*string_divide(t_string str, t_string dlim, int *len)
{
	t_string	*strs;
	size_t		idx;
	size_t		start;

	strs = malloc((word_ncount(str.s, dlim.s, dlim.len) + 1)
			* sizeof(t_string));
	idx = 0;
	start = 0;
	*len = 0;
	while (idx < str.len)
	{
		if (str_cmp(str, dlim, idx) == 0)
			idx += dlim.len;
		start = idx;
		while (idx < str.len && str_cmp(str, dlim, idx) != 0)
			idx++;
		if (idx > start)
			strs[(*len)++] = cstr_to_str_ptr(str.s + start, idx - start);
		idx++;
	}
	if (!*len)
		return (free(strs), NULL);
	strs[*len] = new_str(NULL, 0);
	return (strs);
}

void	string_divide_in_two(t_string str, t_string divided_parts_buf[2],
		t_string dlim, int *num_of_parts)
{
	size_t	idx;
	size_t	start;

	idx = 0;
	start = 0;
	*num_of_parts = 0;
	divided_parts_buf[0] = new_str(NULL, 0);
	divided_parts_buf[1] = new_str(NULL, 0);
	if (str_cmp(str, dlim, idx) == 0)
		idx += dlim.len;
	start = idx;
	while (idx < str.len && str_cmp(str, dlim, idx) != 0)
		idx++;
	if (idx > start)
	{
		divided_parts_buf[0] = cstr_to_str_ptr(str.s + start, idx - start);
		*num_of_parts = 1;
	}
	if (idx < str.len)
	{
		divided_parts_buf[1] = cstr_to_str_ptr(str.s + idx + dlim.len, str.len
				- idx - dlim.len);
		if (divided_parts_buf[1].len > 0)
			*num_of_parts = 2;
	}
}
