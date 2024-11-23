/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:18:51 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:18:51 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TODO: mudar para aceitar a <<capacidade>> 
// como parâmetro para além do tamanho dos dados
t_dynamic_array	*darr_init(size_t ds)
{
	t_dynamic_array	*da;

	da = malloc(sizeof(t_dynamic_array));
	da->data_size = ds;
	da->len = 0;
	da->capacity = DA_INIT_SIZE;
	da->data = malloc(da->data_size * da->capacity);
	return (da);
}

void	darr_append(t_dynamic_array *da, const void *insertion)
{
	size_t	new_capacity;
	void	*new_data;

	if (da->len >= da->capacity)
	{
		new_capacity = da->capacity + DA_INIT_SIZE;
		new_data = ft_realloc(da->data, da->capacity, new_capacity
				* da->data_size);
		da->data = new_data;
		da->capacity = new_capacity;
	}
	ft_memcpy((char *)da->data + da->len * da->data_size, insertion,
		da->data_size);
	da->len++;
}

void *darr_find(t_dynamic_array *da, int (*match) (void *el1, void *el2), void *lookup)
{
	size_t i;
	void **data_array;
	void *res;

	if (!da || !match || !lookup)
		return ;
	res = NULL;
	i = 0;
	data_array = da->data;
	while (i < da->len)
	{
		if (match(data_array[i], lookup) == 0)
		{
			res = data_array[i];
			break ;
		}
		i++;
	}
	return (res);
}

//void darr_remove(t_dymamic_array *da, const void *to_delete)
//{
//	size_t i
//}

//TODO: tenho de incluir o tamanho dos dados aqui como parâmetro?
void darr_sort(t_dynamic_array *da, int (*cmp) (void *el1, void *el2))
{
	size_t i;
	size_t j;
	void *tmp;
	void **data_array;

	if (!da || !da->data || da->len == 1 || !cmp)
		return ;
	i = 0;
	data_array = da->data;
	while (i < da->len)
	{
		j = i;
		while (j < da->len)
		{
			if (cmp(data_array[i], data_array[j]) > 0)
			{
				tmp = data_array[i];
				data_array[i] = data_array[j];
				data_array[j] = tmp;
			}
			j++;
		}
		i++;

	}
}

//TODO: custom_free() func ptr
void	darr_free(t_dynamic_array *da)
{
	if (!da)
		return ;
	free(da->data);
	free(da);
}

/* Usage example
   int	main(void)
   {
   t_dynamic_array	*d;

   d = darr_init(sizeof(int));
   for (int i = 0; i < 10; i++)
   darr_append(d, &i);
   for (int i = 0; i < 10; i++)
   ft_fprintf(OUT, "%d\n", ((int *)d->data)[i]);
   darr_free(d);
   }
   */
