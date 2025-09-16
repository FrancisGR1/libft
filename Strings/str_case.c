/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:49:58 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:19 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	*str_to_upper(const t_string *str)
{
	char	*upper;
	size_t	i;

	if (str == NULL || str->data == NULL)
		return (NULL);
	upper = malloc(sizeof(char) * (str->size + 1));
	i = 0;
	while (i < str->size)
	{
		if (ft_isalpha(str->data[i]) && (str->data[i] >= 'a'
				&& str->data[i] <= 'z'))
		{
			upper[i] = ft_toupper(str->data[i]);
		}
		else
		{
			upper[i] = str->data[i];
		}
		i++;
	}
	upper[str->size] = '\0';
	return (upper);
}

char	*str_to_lower(const t_string *str)
{
	char	*lower;
	size_t	i;

	if (str == NULL || str->data == NULL)
		return (NULL);
	lower = malloc(sizeof(char) * (str->size + 1));
	i = 0;
	while (i < str->size)
	{
		if (ft_isalpha(str->data[i]) && (str->data[i] >= 'A'
				&& str->data[i] <= 'Z'))
		{
			lower[i] = ft_tolower(str->data[i]);
		}
		else
		{
			lower[i] = str->data[i];
		}
		i++;
	}
	lower[str->size] = '\0';
	return (lower);
}

void	str_to_title(t_string *str)
{
	bool	capitalize;
	size_t	i;

	if (str == NULL || str->data == NULL)
		return ;
	capitalize = true;
	i = 0;
	while (i < str->size)
	{
		if (capitalize && ft_isalpha(str->data[i]))
		{
			str->data[i] = ft_toupper(str->data[i]);
			capitalize = false;
		}
		else if (!ft_isalpha(str->data[i]))
			capitalize = true;
		else
			str->data[i] = ft_tolower(str->data[i]);
		i++;
	}
}

void	str_to_capitalize(t_string *str)
{
	if (str == NULL || str->data == NULL || str->size == 0)
		return ;
	str->data[0] = ft_toupper(str->data[0]);
}

void	str_to_casefold(t_string *str)
{
	size_t	i;

	if (str == NULL || str->data == NULL)
		return ;
	i = 0;
	while (i < str->size)
	{
		str->data[i] = ft_tolower(str->data[i]);
		i++;
	}
}
