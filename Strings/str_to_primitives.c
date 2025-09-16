/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_primitives.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:05 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:29 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

int	str_to_int(const t_string *str)
{
	if (str == NULL)
		return (0);
	if (str_empty(str))
		return (0);
	return (ft_atoi(str->data));
}
