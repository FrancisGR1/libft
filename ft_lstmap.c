/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:59:54 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/14 17:29:47 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *))
{
        t_list  **new_lst;
        t_list  *new_ptr;
        t_list  *ptr;

        new_lst = (t_list **)malloc(sizeof(t_list *));
        new_ptr = NULL;
        ptr = lst; 
        while (ptr != NULL)
        {

                new_ptr = (t_list *)malloc(sizeof(t_list));
                new_ptr = ft_lsnew(ptr -> content);
                //printf("\t\t%d\n", *((int*)new_ptr -> content));
                ft_lstadd_front(new_lst, new_ptr);
                //del(ptr -> content);
                //free(ptr -> content);
                ptr = ptr -> next;
        }
        return (*new_lst);
}
   }
