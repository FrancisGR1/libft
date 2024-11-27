/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queues2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:36:13 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:36:28 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queues.h"

bool	q_is_empty(t_queue *q)
{
	return (q == NULL);
}

void	*q_peek(t_queue *q)
{
	if (!q || !q->next)
		return (NULL);
	return (q->next->content);
}

bool	q_last_element(t_queue *q)
{
	return (q && q_peek(q) == NULL);
}

int	q_size(t_queue *q)
{
	return (ft_lstsize(q));
}

void	q_destroy(t_queue **q, void (*del)(void *))
{
	ft_lstclear(q, del);
}
