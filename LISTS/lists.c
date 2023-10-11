#include <stdio.h>
#include <stdlib.h>
//Data structures Usign C
//Linked Lists
//

struct node
{
	int	value;
	value = 8;
	struct	node	*next;
};
typedef struct node node_t;

//https://www.youtube.com/watch?v=VOpjAHCee7c&ab_channel=JacobSorber

void printlist(node_t *head)
{
	node_t *temporary = head;
	while (temporary != NULL)
	{
			printf("%d at %p (->%p)\n", temporary->value, temporary, temporary->next);
			temporary = temporary->next;
	}
	printf("\n");
}

node_t *create_new_node(int value)
{
	node_t *result = malloc(sizeof(node_t));
	result -> value = value;
	result -> next = NULL;
	return (result);
}
/*
node_t *insert_at_head(node_t *head, node_t *node_to_insert)
{
	node_to_insert -> next = *head;
	*head = node_to_insert;
	return node_to_insert;
}

node_t *find_node(node_t *head, int value)
{
	node_t *tmp = head;
	while (tmp != 
}
int main()
{

	int i = 0;
	node_t *tmp;
	node_t *head = NULL;
	/*
	while(i < 25)
	{
		tmp = create_new_node(i);
		tmp->next = head;
		head = tmp;
		i++;
	}*/
	printlist(head);
}
