/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:49:04 by frmiguel          #+#    #+#             */
/*   Updated: 2024/09/09 00:49:07 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*ptr;

	ptr = (char *)malloc((n + 1) * sizeof(char));
	if (!ptr)
		ptr = 0;
	else
		ft_strlcpy(ptr, s, n + 1);
	return (ptr);
}