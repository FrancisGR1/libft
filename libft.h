/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:20:37 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/14 11:59:27 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <ctype.h>
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <string.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include "arena.h"
# include "colors.h"

#define YES 1
#define TRUE 1
#define NO 0
#define FALSE 0
#define OUT STDOUT_FILENO
#define IN STDIN_FILENO
#define ERR STDERR_FILENO

#define DA_INIT_SIZE 50 


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_dynamic_array
{
	void *data;
	size_t len;
	size_t capacity;
	size_t data_size;
}	t_darr;

typedef t_list t_queue; //Dynamic sized queue using a linked list internally

typedef struct s_string
{
	char *s;
	char *end;
	size_t len;
} t_string;

void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_striteri(char *s, void (*f) (unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
void	ft_putns(char *s, int n);
void	ft_puts(char *s);
int	ft_getc(int fd);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del) (void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f) (void *));
size_t	ft_strlen(const char *s);
int	word_count(char const *s, char *delimiter);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int	ft_isspace(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *nptr);
long	ft_atoi_long(const char *nptr);
int	ft_atoi_base(const char *nptr, const char *base_str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_lstsize(t_list *lst);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_until(char const *s1, char const *s2, char until);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(const char *s, char *delimiter);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *));

//strings
t_string	new_str(char *s);
int string_put(t_string s, int fd);
t_string cstr_to_str_ptr(char *raw_str, size_t size);
t_string cstr_to_str(char *raw_str);
int string_find(t_string str, size_t start, size_t n, t_string delimiters);
t_string *string_split(t_string str, t_string delimiters);
t_darr *string_findall(t_string str, t_string targets);

int	ft_snprintf(char buff[], int n, const char *fmt, ...);
int	ft_fprintf(int fd, const char *str, ...);
void	print_bits(char c, int fd);
char	*get_next_line(int fd);
int	ft_digit_count(long int n, int divisor);
void *ft_realloc(void *data, size_t data_size);
void freen(void **data);
void freen_arr(void **data);

//dynamic arrays
t_darr *darr_init(size_t ds);
void darr_append(t_darr *da, const void *insertion);
void darr_free(t_darr *da);

//queues
void q_push(t_queue **q, void *content);
void *q_pop(t_queue **q);
bool q_is_empty(t_queue *q);
void *q_peek(t_queue *q);
bool q_last_element(t_queue *q);
int q_size(t_queue *q);
void q_destroy(t_queue **q, void (*del) (void *));
#endif
