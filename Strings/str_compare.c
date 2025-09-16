/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:49:59 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:20 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

int	str_compare(const t_string *str1, const t_string *str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		if (str1 == str2)
			return (0);
		if (str1 == NULL)
			return (-1);
		if (str2 == NULL)
			return (1);
	}
	return (ft_strcmp(str1->data, str2->data));
}

int	str_compare_ignore_case(const t_string *str1, const t_string *str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		if (str1 == str2)
			return (0);
		if (str1 == NULL)
			return (-1);
		if (str2 == NULL)
			return (1);
	}
	return (ft_strcasecmp(str1->data, str2->data));
}
