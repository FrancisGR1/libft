#ifndef MEMORY_H
# define MEMORY_H

#include "../libft.h"

//memory operations
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);

//allocation
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_realloc(void *data, size_t original_size,
						size_t new_size);
//free and set to null
void				freen(void **data);

//debuggers:
void	*debug_malloc(size_t size, const char *file, int line);
void	debug_free(void *ptr, const char *file, int line);

#endif /*MEMORY_H*/
