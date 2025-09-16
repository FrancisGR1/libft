/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:02 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:25 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

static size_t	get_total_len_of_variadic_strings(size_t count, va_list args);

t_string	*str_join(t_string **strings, int count, const char *delimiter)
{
	t_string	*joint_strings;
	int			i;

	if (strings == NULL || count <= 0 || delimiter == NULL)
		return (NULL);
	joint_strings = str_create("");
	i = 0;
	while (i < count)
	{
		str_append(joint_strings, strings[i]->data);
		if (i < count - 1)
			str_append(joint_strings, delimiter);
		i++;
	}
	return (joint_strings);
}

t_string	*str_join_variadic(size_t count, ...)
{
	va_list		args;
	t_string	*tmp;
	char		*joint_strings;
	char		*current;

	va_start(args, count);
	joint_strings = malloc(get_total_len_of_variadic_strings(count, args) + 1);
	current = joint_strings;
	while (count > 0)
	{
		tmp = va_arg(args, t_string *);
		ft_memcpy(current, tmp->data, tmp->size);
		current += tmp->size;
		count--;
	}
	*current = '\0';
	va_end(args);
	tmp = str_create(joint_strings);
	free(joint_strings);
	return (tmp);
}

static size_t	get_total_len_of_variadic_strings(size_t count, va_list args)
{
	size_t		total_len;
	size_t		i;
	t_string	*tmp;
	va_list		copy_args;

	total_len = 0;
	i = 0;
	va_copy(copy_args, args);
	while (i < count)
	{
		tmp = va_arg(copy_args, t_string *);
		total_len += tmp->size;
		i++;
	}
	va_end(copy_args);
	return (total_len);
}
