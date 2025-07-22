/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:03:23 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:23 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

char	*ft_strncpy(char *dst, char *src, size_t n)
{
	char	*ptr;

	if (dst == NULL || src == NULL || n == 0)
		return (NULL);
	ptr = dst;
	while (*src != '\0' && n > 0)
	{
		*dst++ = *src++;
		n--;
	}
	*dst = '\0';
	return (ptr);
}
