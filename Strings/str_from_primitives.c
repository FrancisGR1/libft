/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_from_primitives.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:49:59 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:20 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

t_string	*str_from_int(int value)
{
	const char	*buffer = ft_itoa(value);
	t_string	*converted;

	converted = str_create(buffer);
	free((char *)buffer);
	return (converted);
}
