#ifndef DYNAMIC_ARRAYS_H
# define DYNAMIC_ARRAYS_H

#include "../../libft.h"

#define DA_DEFAULT_SIZE 50

typedef struct s_dynamic_array
{
	void			*data;
	size_t			len;
	size_t			capacity;
	size_t			data_size;
}					t_dynamic_array;

t_dynamic_array	*darr_init(size_t data_size, size_t capacity);
void				darr_append(t_dynamic_array *da, const void *insertion);
void				darr_free(t_dynamic_array *da);
void darr_sort(t_dynamic_array *da, int (*cmp) (const void *el1, const void *el2));
void *darr_find(t_dynamic_array *da, int (*match) (const void *el1, const void *el2), const void *lookup);
void darr_remove(t_dynamic_array *da, const void *to_delete);

#endif /*DYNAMIC_ARRAYS_H*/
