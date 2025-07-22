/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queues.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:12:50 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:13:02 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUES_H
# define QUEUES_H

# include "../../libft.h"

// Dynamic sized queue using a linked list internally
typedef struct s_list		t_queue;

// queues
void				q_push(t_queue **q, void *content);
void				*q_pop(t_queue **q);
bool				q_is_empty(t_queue *q);
void				*q_peek(t_queue *q);
bool				q_last_element(t_queue *q);
int					q_size(t_queue *q);
void				q_destroy(t_queue **q, void (*del)(void *));

#endif /*QUEUES_H*/
