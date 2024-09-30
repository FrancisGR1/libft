#include "libft.h"

void q_push(t_queue **q, void *content)
{
	t_queue *new;

	new = malloc(sizeof(t_queue));
	if (!new)
		return ;
	new->content = content;
	new->next = NULL;
	ft_lstadd_back(q, new);
}

void *q_pop(t_queue **q)
{
	void *pop;
	t_queue *tmp;

	if (!q || !*q)
		return (NULL);
	pop = (*q)->content;
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
	return (pop);

}

bool q_is_empty(t_queue *q)
{
	return (q == NULL);
}

void *q_peek(t_queue *q)
{
	if (!q || !q->next)
		return (NULL);
	return (q->next->content);
}

bool q_last_element(t_queue *q)
{
	return (q && q_peek(q) == NULL);
}

int q_size(t_queue *q)
{
	return (ft_lstsize(q));
}

void q_destroy(t_queue **q, void (*del) (void *))
{
	ft_lstclear(q, del);
}

//EXAMPLE USAGE
/*
void main(void)
{
	t_queue *q = NULL;
	int i1 = 1;
	int i2 = 2;
	int i3 = 3;
	int i4 = 4;
	int i5 = 5;
	q_push(&q, &i1);
	q_push(&q, &i2);
	q_push(&q, &i3);
	q_push(&q, &i4);
	q_push(&q, &i5);
	printf("size: %d\n", q_size(q));
	while (!q_is_empty(q))
	{
		if (q_peek(q))
			printf("has one extra el at least\n");
		if (q_last_element(q))
			printf("last el:\n");
		int *res = (int *)q_pop(&q);
		printf("%d\n", *res);
	}
	q_push(&q, &i4);
	q_push(&q, &i5);
	q_destroy(&q, NULL);
}
*/
