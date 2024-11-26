#ifndef QUEUES_H
# define QUEUES_H

// Dynamic sized queue using a linked list internally
typedef t_list		t_queue;

// queues
void				q_push(t_queue **q, void *content);
void				*q_pop(t_queue **q);
bool				q_is_empty(t_queue *q);
void				*q_peek(t_queue *q);
bool				q_last_element(t_queue *q);
int					q_size(t_queue *q);
void				q_destroy(t_queue **q, void (*del)(void *));

#endif /*QUEUES_H*/
