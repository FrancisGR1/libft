/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_internals.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:02:12 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:02:12 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_INTERNALS_H
# define ARENA_INTERNALS_H

# include "../libft.h"

// find/save next arena data ptr
void	_arena_save_ptr(t_dynamic_array *to_save, void *ptr);
void	*_arena_lookup_next_ptr(t_arena *arena, void *curr_ptr);

// find arena which includes the ptr
t_arena	*_arena_of_ptr(t_arena *arena_list, void *ptr);

// remove or move reset chunk after being reused
void	*_arena_reorder_reset_chunk(t_dynamic_array *reset_chunks,
			void *reset_chunk_ptr, size_t size_bytes, size_t size_available);
void	_arena_move_reset_chunk_ptr(void **reset_chunk_ptr, size_t size_used);
void	*_arena_use_reset_chunk(t_arena *arena_list, size_t size_bytes);

#endif /*ARENA_INTERNALS_H*/
