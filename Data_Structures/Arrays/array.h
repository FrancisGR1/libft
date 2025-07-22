/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:06:24 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:06:55 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include "../../libft.h"

// free data
void	freen_arr(void **data);

void	freen_arr_with_custom_func(void **data, void (*del)(void *));

// size of array
size_t	array_len(void **arr);
#endif /*ARRAY_H*/
