/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:07:03 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:07:19 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNAMIC_ARRAY_H
# define DYNAMIC_ARRAY_H

# include "../../libft.h"

# define DA_DEFAULT_SIZE 50

typedef struct s_dynamic_array
{
	void		*data;
	size_t		len;
	size_t		capacity;
	size_t		data_size;
}				t_dynamic_array;

t_dynamic_array	*darr_init(size_t data_size, size_t capacity);
void			darr_append(t_dynamic_array *da, const void *insertion);
void			darr_sort(t_dynamic_array *da, int (*cmp)(const void *el1,
						const void *el2));
void			*darr_find(t_dynamic_array *da, int (*match)(const void *el1,
						const void *el2), const void *lookup);
void			darr_remove(t_dynamic_array *da, const void *to_delete);

// free data
void			darr_free(t_dynamic_array *da);
void			darr_free_custom(t_dynamic_array *da, void (*del)(void *data));

#endif /*DYNAMIC_ARRAY_H*/
