/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:18:59 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:18:59 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

// Esta função é horrível mas para os meus propósitos é mais do que suficiente
int	ft_rand(void)
{
	static unsigned long	next = 1;

	next = next * 1103515245 + 12345;
	return ((unsigned)(next / 65536) % 32768);
}
