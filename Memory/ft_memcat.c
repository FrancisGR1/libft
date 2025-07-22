/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:18:56 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:15:16 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memcat(void *dst, void *src, size_t dst_offset, size_t data_cnt)
{
	unsigned char	*dst_with_offset;

	if (!dst || !src)
		return (NULL);
	dst_with_offset = (unsigned char *)(dst + dst_offset);
	while (data_cnt--)
		*dst_with_offset = *(unsigned char *)src++;
	return (dst);
}
