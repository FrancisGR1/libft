/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:49:04 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:23 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = ft_calloc(n + 1, sizeof(char));
	if (!ptr)
		ptr = 0x0;
	else
		ft_strlcpy(ptr, s, n + 1);
	return (ptr);
}
