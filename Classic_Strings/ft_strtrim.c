/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:39:06 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:25 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

static int	is_charset(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	get_len(char const *s, char const *set)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] && is_charset(s[start], set))
		start++;
	while (end >= 0 && is_charset(s[end], set))
		end--;
	if (end < start)
		return (0);
	return (end - start + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	i;
	size_t	end;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	p = malloc(get_len(s1, set) + 1 * sizeof(char));
	if (!p)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && is_charset(s1[start], set))
		start++;
	while (end >= start && is_charset(s1[end], set))
		end--;
	i = 0;
	while (s1[start] && start <= end)
		p[i++] = s1[start++];
	p[i] = '\0';
	return (p);
}
/*
int main (int c, char **v)
{
char		*str = c > 1 ? v[1] : "Hello";
char		*sep = c > 2 ? v[2] : "Hho";
char		*trmstr = ft_strtrim(str, sep);
int			len = get_len(str, sep);

printf("%d\n", len);
printf("%s\n%s\n%s\n", str, sep, trmstr);
}
*/
