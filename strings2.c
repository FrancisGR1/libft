/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:43:31 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:46:12 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string	str_join(int strs_num, int strs_size, ...)
{
	va_list		args;
	t_string	res;
	t_string	current;

	va_start(args, strs_size);
	res.s = malloc(strs_size + 1);
	res.type = STR_ALLOCATED;
	res.len = 0;
	while (strs_num)
	{
		current = va_arg(args, t_string);
		ft_strlcpy(res.s + res.len, current.s, current.len + 1);
		res.len += current.len;
		strs_num--;
	}
	res.s[res.len] = '\0';
	va_end(args);
	return (res);
}

t_string	str_cat(t_string s1, t_string s2)
{
	t_string	res;

	if (str_is_null(s1) && str_is_null(s2))
		return (new_str(NULL, 0));
	if (str_is_null(s1))
		return (s2);
	if (str_is_null(s2))
		return (s1);
	res.len = s1.len + s2.len;
	res.s = malloc(res.len + 1);
	if (!res.s)
		return (new_str(NULL, 0));
	res.type = STR_ALLOCATED;
	if (ft_strlcpy(res.s, s1.s, s1.len + 1) == 0)
		res.s[0] = '\0';
	if (ft_strlcat(res.s, s2.s, res.len + 1) == 0)
		res.s[s1.len] = '\0';
	res.end = res.s + s1.len + s2.len;
	return (res);
}

void	str_free_and_replace_raw(t_string *str, char *raw_str)
{
	if (!str || str_is_null(*str))
		return ;
	if (str->type == STR_ALLOCATED)
		string_free(str);
	*str = cstr_to_str(raw_str);
}

void	str_free_and_replace_str(t_string *str, t_string *substitute)
{
	if (!str || str_is_null(*str))
		return ;
	if (str->type == STR_ALLOCATED)
		string_free(str);
	*str = *substitute;
}

t_dynamic_array	*string_findall(t_string str, char *delimiters)
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
