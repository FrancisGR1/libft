/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queues.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:19:04 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:19:04 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queues.h"

void	q_push(t_queue **q, void *content)
{
	t_queue	*new;

	new = malloc(sizeof(t_queue));
	if (!new)
		return ;
	new->content = content;
	new->next = NULL;
	ft_lstadd_back(q, new);
}

void	*q_pop(t_queue **q)
{
	void	*data;
	t_queue	*tmp;

	if (!q || !*q)
		return (NULL);
	data = (*q)->content;
	if ((*q)->next == NULL)
	{
		free(*q);
		*q = NULL;
	}
	else
	{
		tmp = *q;
		(*q) = (*q)->next;
		free(tmp);
	}
	return (data);
}

// EXAMPLE USAGE
/*
void	main(void)
{
	t_queue	*q;
	int		i1;
	int		i2;
	int		i3;
	int		i4;
	int		i5;
	int		*res;

	q = NULL;
	i1 = 1;
	i2 = 2;
	i3 = 3;
	i4 = 4;
	i5 = 5;
	q_push(&q, &i1);
	q_push(&q, &i2);
	q_push(&q, &i3);
	q_push(&q, &i4);
	q_push(&q, &i5);
	printf("size: %d\n", q_size(q));
	while (!q_is_empty(q))
	{
		if (q_peek(q))
			printf("has one extra el\n");
		if (q_last_element(q))
			printf("last el:\n");
		res = (int *)q_pop(&q);
		printf("%d\n", *res);
	}
	q_push(&q, &i4);
	q_push(&q, &i5);
	q_destroy(&q, NULL);
}
*/
