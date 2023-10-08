/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:08:37 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/08 17:14:56 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		uc;
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (n)
	{
		if (*ptr == uc)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
