/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:12:19 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:12:19 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

# include "../../libft.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// initialization
t_list				*ft_lstnew(void *content);

// get last node
t_list				*ft_lstlast(t_list *lst);

// size of list
int					ft_lstsize(t_list *lst);

// duplicate list
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
// iterate
void				ft_lstiter(t_list *lst, void (*f)(void *));

// push
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);

// free
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
int					ft_lstrem_node(t_list *prev, t_list *to_delete,
						void (*del)(void *));
#endif /*LISTS_H*/
