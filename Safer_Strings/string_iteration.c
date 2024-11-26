/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:43:31 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:44:03 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safer_strings.h"

int	str_iter(t_string str, size_t start, size_t n, int (*iterator)(int c))
{
	if (str_is_null(str))
		return (-1);
	while (iterator(str.s[start]) && n)
	{
		start++;
		n--;
	}
	return (start);
}

bool	str_advance_ptr(t_string *str)
{
	if (!str || str_is_null(*str) || str->s == str->end)
		return (false);
	str->s++;
	str->len--;
	return (true);
}

bool	str_advance_ptr_ntimes(t_string *str, int n)
{
	t_string	original_str;

	original_str = str_save_state(*str);
	while (n)
	{
		if (!str_advance_ptr(str))
		{
			str_restore_state(str, original_str);
			return (false);
		}
		n--;
	}
	return (true);
}
