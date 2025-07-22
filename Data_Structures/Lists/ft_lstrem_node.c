/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrem_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:12:18 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:12:18 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

int	ft_lstrem_node(t_list *prev, t_list *to_delete, void (*del)(void *))
{
	t_list	*next;

	if (!prev || !to_delete)
		return (-1);
	next = to_delete->next;
	if (del)
		del(to_delete->content);
	freen((void *)&to_delete);
	prev->next = next;
	return (0);
}
