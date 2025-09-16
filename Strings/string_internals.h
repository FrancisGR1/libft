/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_internals.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:01 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:22 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_INTERNALS_H
# define STRING_INTERNALS_H

# include <stddef.h>

typedef struct s_string_memory
{
	void		*memory;
	size_t		size;
	size_t		capacity;
}				t_string_memory;

// memory management
t_string_memory	*_memory_create(size_t capacity);
void			*_region_allocate(t_string_memory *region, size_t size);
void			_memory_destroy(t_string_memory *memory);

#endif /*STRING_INTERNALS_H*/
