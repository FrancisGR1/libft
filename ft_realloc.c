/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:18:59 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:18:59 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *data, size_t original_size, size_t new_size)
{
	void	*new;
	size_t	copy_size;

	if (!data)
		return (ft_calloc(new_size, 1));
	if (!new_size)
	{
		free(data);
		return (NULL);
	}
	new = ft_calloc(new_size, 1);
	if (!new)
		return (NULL);
	if (original_size < new_size)
		copy_size = original_size;
	else
		copy_size = new_size;
	ft_memcpy(new, data, copy_size);
	free(data);
	return (new);
}
