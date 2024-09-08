/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:21:23 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/11 11:55:26 by frmiguel         ###   ########.fr       */
/*                                                                          */
/* ************************************************************************** */
#include "libft.h"

static int	is_delimiter(char c, char *delimiter)
{
	while (*delimiter)
	{
		if (*delimiter == c)
			return (TRUE);
		delimiter++;
	}
	return (FALSE);
}

static int	word_count(char const *s, char *delimiter)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && is_delimiter(s[i], delimiter))
			i++;
		if (s[i] && !is_delimiter(s[i], delimiter))
			cnt++;
		while (s[i] && !is_delimiter(s[i], delimiter))
			i++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char *delimiter)
{
	char	**p;
	int		words;
	int		i;
	int		len;

	words = word_count(s, delimiter);
	p = (char **)malloc((words + 1) * sizeof(char *));
	i = 0;
	while (i < words)
	{
		len = 0;
		while (*s && !is_delimiter(*s, delimiter))
		{
			len++;
			s++;
		}
		if (len)
			p[i++] = ft_strndup(s - len, len);
		while (*s && is_delimiter(*s, delimiter))
			s++;
	}
	p[words] = NULL;
	return (p);
}

/*
int main(int c, char **v)
{
	char *str = c > 1 ? v[1] : " Hello There ";
	char sep = c > 2 ? v[2][0] : ' ';
	int result = word_count(str, sep);
	printf("Str:%s\nSep: %c\nNum of Words: %d\nArray:\n", str, sep, result);
	char	**arr = ft_split(str, sep);
	int i = 0;
	while (i < result)
	{
		printf("%s\n", arr[i]);
		i++;
	}
	free_arr(arr, i);
}
*/
