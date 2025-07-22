/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_until.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:18:54 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:18 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

size_t	ft_len_until(char *s, char c)
{
	const char	*ch_pos = (const char *)ft_strchr(s, c);

	if (ch_pos)
	{
		return ((size_t)(ch_pos - s));
	}
	return (ft_strlen(s));
}
