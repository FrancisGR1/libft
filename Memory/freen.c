/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:18:51 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:18:51 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	freen(void **data)
{
	if (!data || !*data)
		return ;
	free(*data);
	*data = NULL;
}

