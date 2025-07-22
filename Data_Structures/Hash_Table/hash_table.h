/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:08:03 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:08:54 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include "../../libft.h"

// Chained hash table
typedef struct s_hash_table
{
	size_t			capacity;
	size_t			elements;
	int				(*hash)(const void *key);
	int				(*match)(const void *key1, const void *key2);
	struct s_list	**table;
}					t_ht;

int					ht_init(t_ht **ht, int capacity,
						int (*hash)(const void *key),
						int (*match)(const void *key1, const void *key2));
void				ht_destroy(t_ht *ht, void (*del)(void *data));
int					ht_insert(t_ht *ht, const void *data);
int					ht_remove(t_ht *ht, void **data, void (*del)(void *));
int					ht_lookup(t_ht *ht, void **data);
int					ht_size(t_ht *ht);

// hash functions
int					hash_str(const void *key);

#endif /*HASH_TABLE_H*/
