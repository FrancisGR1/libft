#include "lists.h"

int ft_lstrem_node(t_list *prev, t_list *to_delete, void (*del)(void *))
{
	t_list *next;

	if (!prev || !to_delete)
		return (-1);
	next = to_delete->next;
	if (del)
		del(to_delete->content);
	freen((void *)&to_delete);
	prev->next = next;
	return (0);
}
