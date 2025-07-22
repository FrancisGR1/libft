/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_watermark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:02:13 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:02:13 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "arena_internals.h"

void	arena_set_watermark(t_arena *arena)
{
	if (!arena)
		return ;
	while (arena->next)
	{
		arena = arena->next;
	}
	arena->watermark = arena->memory + arena->current_size;
}

void	arena_reset_to_watermark(t_arena *arena)
{
	size_t	bytes_to_reset;

	if (!arena)
		return ;
	while (arena)
	{
		if (arena->watermark)
		{
			bytes_to_reset = arena->end - arena->watermark;
			ft_memset(arena->watermark, 0, bytes_to_reset);
			arena_destroy(arena->next);
		}
		arena = arena->next;
	}
}
