/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:08:03 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:11:52 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

// Credit to Kyle Loudon and his book "Mastering Algorithms"
int	hash_str(const void *key)
{
	const char	*str;
	size_t		res;
	size_t		tmp;

	res = 0;
	str = key;
	while (*str)
	{
		res = (res << 4) + *str;
		tmp = (res & 0xf0000000);
		if (tmp)
		{
			res = res ^ (tmp >> 24);
			res = res ^ tmp;
		}
		str++;
	}
	return (res);
}

//@NOTE: should be in hash_table.c but norminette...
int	ht_size(t_ht *ht)
{
	return (ht->elements);
}
