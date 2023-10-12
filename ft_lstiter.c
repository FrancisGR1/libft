/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:33:03 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/12 23:38:22 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (void *))
{
	t_list	*ptr;

	ptr = lst;
	if (lst == NULL)
		return ;
	while (ptr != NULL)
	{
		f(ptr -> content);
		ptr = ptr -> next;
	}
}
