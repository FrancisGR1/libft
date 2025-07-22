/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classic_strings.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:03:16 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:16 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSIC_STRINGS_H
# define CLASSIC_STRINGS_H

# include "../libft.h"

# define ASCII_SIZE 256

// measure
size_t	ft_strlen(const char *s);
size_t	ft_len_until(char *s, char c);
int		word_ncount(char const *s, char *delimiter, int dn);

// check
int		ft_islower(char c);
int		ft_isupper(char c);

// copy
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strncpy(char *dst, char *src, size_t n);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);

// cat
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_until(char const *s1, char const *s2, char until);

// compare
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strcasecmp(const char *s1, const char *s2);

// find
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strstr(const char *big, const char *little);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// modify
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_toupper(int c);
int		ft_tolower(int c);

// convert to number
int		ft_atoi(const char *nptr);
long	ft_atoi_long(const char *nptr);
int		ft_atoi_base(const char *nptr, const char *base_str);

// convert number to string
char	*ft_itoa(int n);

// tokenization
char	*ft_strtok(char *s, const char *delim);
size_t	ft_strspn(char *s, const char *delim);
size_t	ft_strcspn(char *s, const char *delim);

// split
char	**ft_split(char const *s, char *delimiter);

// randomized string
char	*rand_string(void);

#endif /*CLASSIC_STRINGS_H */
