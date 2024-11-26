#ifndef MEMORY_H
# define MEMORY_H

void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_realloc(void *data, size_t original_size,
						size_t new_size);
void				ft_bzero(void *s, size_t n);
void				freen(void **data);

#endif /*MEMORY_H*/
