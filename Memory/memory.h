/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:15:18 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:15:18 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include "../libft.h"

// memory operations
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		cmp_ptrs(const void *el1, const void *el2);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);

// allocation
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *data, size_t original_size, size_t new_size);
void	*ft_realloc_custom_cpy(void *data, size_t original_size,
			size_t new_size, void *cpy(void *, void *, size_t));

// free and set to null
void	freen(void **data);

// swap
void	swap_bytes(void *el1, void *el2, size_t data_size);

// debuggers:
void	*debug_malloc(size_t size, const char *file, int line);
void	debug_free(void *ptr, const char *file, int line);

#endif /*MEMORY_H*/
