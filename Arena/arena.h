/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:27:32 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:05:44 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include "../libft.h"

// Default size of allocation
# define DEFAULT_ALLOC_SIZE 1024
// Initial size to store ptrs do data
# define START_PTRS 20
// Initial size to store ptrs to freed chunks
# define RESET_CHUNKS 20

typedef struct s_arena
{
	size_t					limit;
	size_t					current_size;
	void					*memory;
	void					*end;
	void					*watermark;
	struct s_dynamic_array	*data_ptrs;
	struct s_dynamic_array	*reset_chunks;
	struct s_arena			*next;
}							t_arena;

t_arena						*arena_init(size_t size);
void						*arena_alloc(t_arena **region, size_t nbytes,
								size_t size);
void						arena_reset(t_arena *arena_list, void *ptr);
void						arena_destroy(t_arena *arena);
void						arena_visualizer(char *msg, t_arena *region);
void						arena_set_watermark(t_arena *arena);
void						arena_reset_to_watermark(t_arena *arena);

#endif /*ARENA_H*/
