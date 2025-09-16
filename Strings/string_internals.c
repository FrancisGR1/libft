/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_internals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:00 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:34:00 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_internals.h"
#include "strings.h"

t_string_memory	*_memory_create(size_t capacity)
{
	t_string_memory	*new_region;

	if (capacity == 0)
		return (NULL);
	new_region = malloc(sizeof(t_string_memory));
	if (new_region)
	{
		new_region->memory = ft_calloc(sizeof(char), capacity);
		if (new_region->memory == NULL)
		{
			ft_fprintf(STDERR, "Error: allocation for string failed\n");
			free(new_region);
			return (NULL);
		}
		new_region->size = 0;
		new_region->capacity = capacity;
	}
	else
	{
		ft_fprintf(STDERR, "Error: allocation for t_string_memory failed\n");
		return (NULL);
	}
	return (new_region);
}

void	*_region_allocate(t_string_memory *region, size_t size)
{
	void	*memory_ptr;

	if (region == NULL)
	{
		ft_fprintf(STDERR, "Error: memory region is NULL\n");
		return (NULL);
	}
	if (region->size + size > region->capacity)
	{
		ft_fprintf(STDERR,
			"Error: memory region out of size. Bytes requested: \
			%d; available: %d; used: %d\n",
			size,
			region->capacity - region->size,
			region->size);
		return (NULL);
	}
	memory_ptr = (char *)region->memory + region->size;
	region->size += size;
	return (memory_ptr);
}

void	_memory_destroy(t_string_memory *region)
{
	if (region == NULL)
	{
		ft_fprintf(STDERR, "Error: attempting to destroy a NULL region\n");
		return ;
	}
	if (region->memory == NULL)
	{
		ft_fprintf(STDERR,
			"Error: attempting to destroy a NULL memory region\n");
	}
	else
	{
		free(region->memory);
	}
	free(region);
}
