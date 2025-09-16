/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arithmetics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:49:58 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:19 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

bool	str_is_equal(const t_string *str1, const t_string *str2)
{
	return (str_compare(str1, str2) == 0);
}

bool	str_is_not_equal(const t_string *str1, const t_string *str2)
{
	return (str_compare(str1, str2) != 0);
}

bool	str_is_less(const t_string *str1, const t_string *str2)
{
	return (str_compare(str1, str2) < 0);
}

bool	str_is_greater(const t_string *str1, const t_string *str2)
{
	return (str_compare(str1, str2) > 0);
}
