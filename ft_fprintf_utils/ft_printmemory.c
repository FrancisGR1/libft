/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:08:25 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/17 21:48:32 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_printmemory(int fd, unsigned long n)
{
	int	count;

	write(fd, "0x", 2);
	count = ft_tohexa(fd, 'l', n);
	return (count + 2);
}
