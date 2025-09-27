/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_p2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:02 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/27 10:26:47 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

bool	str_is_space(const t_string *str)
{
	size_t	i;

	if (str == NULL || str->data == NULL)
		return (false);
	i = 0;
	while (str->data[i] != '\0' && ft_isspace(str->data[i]))
	{
		i++;
	}
	return (str->data[i] == '\0');
}

bool	str_is_printable(const t_string *str)
{
	size_t	i;

	if (str == NULL || str->data == NULL)
		return (false);
	i = 0;
	while (str->data[i] != '\0' && ft_isprint(str->data[i]))
	{
		i++;
	}
	return (str->data[i] == '\0');
}

bool	str_is_only_this(const t_string *str, bool (*f)(char))
{
	size_t	i;

	if (str == NULL || str->data == NULL || f == NULL)
		return (false);
	i = 0;
	while (str->data[i] != '\0' && f(str->data[i]))
	{
		i++;
	}
	return (str->data[i] == '\0');
}
