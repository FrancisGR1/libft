/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:02 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:24 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

bool	str_is_alpha(const t_string *str)
{
	size_t	i;

	if (str == NULL || str->data == NULL)
		return (false);
	i = 0;
	while (str->data[i] != '\0' && ft_isalpha(str->data[i]))
	{
		i++;
	}
	return (str->data[i] == '\0');
}

bool	str_is_digit(const t_string *str)
{
	size_t	i;

	if (str == NULL || str->data == NULL)
		return (false);
	i = 0;
	while (str->data[i] != '\0' && ft_isdigit(str->data[i]))
	{
		i++;
	}
	return (str->data[i] == '\0');
}

bool	str_is_alnum(const t_string *str)
{
	size_t	i;

	if (str == NULL || str->data == NULL)
		return (false);
	i = 0;
	while (str->data[i] != '\0' && ft_isalnum(str->data[i]))
	{
		i++;
	}
	return (str->data[i] == '\0');
}

bool	str_is_lower(const t_string *str)
{
	size_t	i;

	if (str == NULL || str->data == NULL)
		return (false);
	i = 0;
	while (str->data[i] != '\0' && ft_islower(str->data[i]))
	{
		i++;
	}
	return (str->data[i] == '\0');
}

bool	str_is_upper(const t_string *str)
{
	size_t	i;

	if (str == NULL || str->data == NULL)
		return (false);
	i = 0;
	while (str->data[i] != '\0' && ft_isupper(str->data[i]))
	{
		i++;
	}
	return (str->data[i] == '\0');
}
