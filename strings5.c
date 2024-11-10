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

#include "libft.h"

int	str_cmp(t_string s1, t_string s2, size_t s1_start)
{
	size_t	i;

	i = 0;
	while (s1.s[s1_start] == s2.s[i] && s1_start < s1.len && i < s2.len)
	{
		s1_start++;
		i++;
	}
	return (s1.s[s1_start] - s2.s[i]);
}

t_string	str_dup(t_string to_duplicate)
{
	t_string	dup;
	int			copied_chars;

	if (str_is_null(to_duplicate))
		return (new_str(NULL, 0));
	dup.len = to_duplicate.len;
	dup.s = malloc(dup.len + 1);
	dup.type = STR_ALLOCATED;
	copied_chars = ft_strlcpy(dup.s, to_duplicate.s, dup.len + 1);
	if (!copied_chars)
		dup.s[0] = '\0';
	dup.end = dup.s + copied_chars;
	return (dup);
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

char	*string_convert_back(t_string str)
{
	char	*s;

	if (str_is_null(str))
		return (NULL);
	s = malloc(str.len + 1);
	if (!s)
		return (NULL);
	if (ft_strlcpy(s, str.s, str.len + 1) == 0)
		s[0] = '\0';
	return (s);
}
