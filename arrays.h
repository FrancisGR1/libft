#ifndef ARRAYS_H
# define ARRAYS_H

//free data
void				freen_arr(void **data);

void				freen_arr_with_custom_func(void **data,
						void (*del)(void *));

//size of array
size_t				array_len(void **arr);
# endif /*ARRAYS_H*/
