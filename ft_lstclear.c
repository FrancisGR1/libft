/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:25:36 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/14 21:33:48 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*ptr;
	t_list	*tmp;

	if (lst == NULL)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr -> next;
		if (del != NULL)
			del(tmp -> content);
		free(tmp);
	}
	*lst = NULL;
}
