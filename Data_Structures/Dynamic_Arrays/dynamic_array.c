/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:18:51 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:07:03 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_array.h"

t_dynamic_array	*darr_init(size_t data_size, size_t capacity)
{
	t_dynamic_array	*da;

	da = malloc(sizeof(t_dynamic_array));
	da->data_size = data_size;
	da->len = 0;
	da->capacity = capacity;
	da->data = malloc(da->data_size * da->capacity);
	return (da);
}

void	darr_append(t_dynamic_array *da, const void *insertion)
{
	size_t	new_capacity;
	void	*new_data;

	if (da->len >= da->capacity)
	{
		new_capacity = da->capacity + DA_DEFAULT_SIZE;
		new_data = ft_realloc(da->data, da->capacity * da->data_size,
				new_capacity * da->data_size);
		da->data = new_data;
		da->capacity = new_capacity;
	}
	ft_memcpy((char *)da->data + da->len * da->data_size, insertion,
		da->data_size);
	da->len++;
}

void	*darr_find(t_dynamic_array *da, int (*match)(const void *el1,
			const void *el2), const void *lookup)
{
	size_t	i;
	size_t	offset;
	void	*curr;
	void	*res;

	if (!da || !match || !lookup)
		return (NULL);
	res = NULL;
	offset = 0;
	i = 0;
	while (i < da->len)
	{
		offset = i * da->data_size;
		curr = da->data + offset;
		if (match(curr, lookup) == 0)
		{
			res = curr;
			break ;
		}
		i++;
	}
	return (res);
}

void	darr_remove(t_dynamic_array *da, const void *to_delete)
{
	size_t	i;
	size_t	bytes;
	size_t	offset;
	void	*curr;

	if (!da || !to_delete)
		return ;
	bytes = 0;
	offset = 0;
	i = 0;
	while (i < da->len)
	{
		offset = i * da->data_size;
		curr = da->data + offset;
		if (cmp_ptrs(curr, to_delete) == 0)
		{
			bytes = (da->len - i) * da->data_size;
			ft_memmove(curr, curr + da->data_size, bytes);
			da->len--;
			break ;
		}
		i++;
	}
}

void	darr_sort(t_dynamic_array *da, int (*cmp)(const void *el1,
			const void *el2))
{
	size_t	i;
	size_t	j;
	void	*curr;

	if (!da || !da->data || da->len == 1 || !cmp)
		return ;
	i = 0;
	curr = da->data;
	while (i < da->len)
	{
		j = i;
		while (j < da->len)
		{
			if (cmp(curr + (i * da->data_size), curr + (j * da->data_size)) > 0)
				swap_bytes(curr + (i * da->data_size), curr + (j
						* da->data_size), da->data_size);
			j++;
		}
		i++;
	}
}

/*
//TEMP
int	cmp_nums(const void *el1, const void *el2)
{
dprintf(STDOUT, "cmp res: %lld\n",  *(long long *)el1 - *(long long *)el2);
return (*(long long *)el1 - *(long long *)el2);
}

// Usage example
int	main(void)
{
int				num[1];
t_dynamic_array	*d;
void			*to_delete = darr_find(d, cmp_nums, num);

num[0] = 1;
d = darr_init(sizeof(int));
for (int i = 0; i < 10; i++)
darr_append(d, &i);
for (int i = 0; i < d->len; i++)
ft_fprintf(STDOUT, "%d\n", ((int *)d->data)[i]);
darr_remove(d, to_delete);
ft_fprintf(STDOUT, "AFTER REMOVING\n");
for (int i = 0; i < d->len; i++)
ft_fprintf(STDOUT, "%d\n", ((int *)d->data)[i]);
darr_free(d);
}
*/
