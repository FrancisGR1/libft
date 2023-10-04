#ifndef FT_H
# define FT_H

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int	ft_isprint(int c);


#endif
