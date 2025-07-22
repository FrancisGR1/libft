/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:08:03 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:12:03 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

int	ht_init(t_ht **ht, int capacity, int (*hash)(const void *key),
		int (*match)(const void *key1, const void *key2))
{
	*ht = ft_calloc(sizeof(t_ht), 1);
	if (!*ht)
		return (-1);
	(*ht)->capacity = capacity;
	(*ht)->elements = 0;
	(*ht)->table = ft_calloc(sizeof(t_list *), capacity);
	if (!(*ht)->table)
		return (-1);
	(*ht)->hash = hash;
	(*ht)->match = match;
	return (0);
}

void	ht_destroy(t_ht *ht, void (*del)(void *data))
{
	size_t	i;

	i = 0;
	while (i < ht->capacity)
	{
		ft_lstclear(&(ht->table[i]), del);
		i++;
	}
	free(ht->table);
	freen((void *)&ht);
}

int	ht_insert(t_ht *ht, const void *data)
{
	void	*ptr;
	int		index;

	ptr = (void *)data;
	if (ht_lookup(ht, &ptr) == 0)
		return (1);
	index = ht->hash(data) % ht->capacity;
	ft_lstadd_back(&(ht->table[index]), ft_lstnew(ptr));
	ht->elements++;
	return (0);
}

int	ht_remove(t_ht *ht, void **data, void (*del)(void *))
{
	int		index;
	t_list	*lst_ptr;
	t_list	*prev;

	index = ht->hash(*data) % ht->capacity;
	lst_ptr = ht->table[index];
	prev = lst_ptr;
	while (lst_ptr)
	{
		if (ht->match(*data, lst_ptr->content))
		{
			ft_lstrem_node(prev, lst_ptr, del);
			ht->elements--;
			return (0);
		}
		prev = lst_ptr;
		lst_ptr = lst_ptr->next;
	}
	return (-1);
}

int	ht_lookup(t_ht *ht, void **data)
{
	int		index;
	t_list	*lst_ptr;

	index = ht->hash(*data) % ht->capacity;
	lst_ptr = ht->table[index];
	while (lst_ptr)
	{
		if (ht->match(*data, lst_ptr->content))
		{
			*data = lst_ptr->content;
			return (0);
		}
		lst_ptr = lst_ptr->next;
	}
	return (-1);
}
