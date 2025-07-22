/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debuggers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:18:51 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:15:15 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

/*
#if defined DEBUG_REPLACE && DEBUG_REPLACE == 1
void	*debug_malloc(size_t size, const char *file, int line)
{
	void	*ptr;

# undef malloc // disable macro temporarily
	ptr = malloc(size);
# define malloc(size) debug_malloc(size, __FILE__, __LINE__)
	if (!ptr)
		return (NULL);
	ft_fprintf(STDOUT, "%s:%d\n\talloc: \t%p\n", file, line, ptr);
	return (ptr);
}

void	debug_free(void *ptr, const char *file, int line)
{
	ft_fprintf(STDOUT, "%s:%d\n\tfreed: \t%p\n", file, line, ptr);
# undef free // disable free temporarily
	free(ptr);
# define free(ptr) debug_free(ptr, __FILE__, __LINE__)
}

# define malloc(size) debug_malloc(size, __FILE__, __LINE__)
# define free(ptr) debug_free(ptr, __FILE__, __LINE__)

#endif

*/
