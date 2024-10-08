/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:25:14 by frmiguel          #+#    #+#             */
/*   Updated: 2024/01/06 15:25:16 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putns(char *s, int n)
{
	if (!s)
	{
		ft_fprintf(STDERR_FILENO, "Error: NULL\n", n);
		return ;
	}
	if (n < 1)
	{
		ft_fprintf(STDERR_FILENO, "Error: n size\n", n);
		return ;
	}
	write(STDOUT_FILENO, s, n);
	write(STDOUT_FILENO, "\n", 1);
}
