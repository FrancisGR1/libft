/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:03:19 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:19 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:21:23 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:18:59 by frmiguel         ###   ########.fr       */
/*                                                                          */
/* ************************************************************************** */

#include "classic_strings.h"

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

int	word_ncount(char const *s, char *delimiter, int len)
{
	int	cnt;
	int	i;

	if (!s || !delimiter)
		return (0);
	cnt = 0;
	i = 0;
	while (s[i] && len)
	{
		while (s[i] && is_delimiter(s[i], delimiter))
		{
			i++;
			len--;
		}
		if (s[i] && !is_delimiter(s[i], delimiter))
			cnt++;
		while (s[i] && !is_delimiter(s[i], delimiter))
		{
			i++;
			len--;
		}
	}
	return (cnt);
}

char	**ft_split(char const *s, char *delimiter)
{
	char	**p;
	int		words;
	int		i;
	int		len;

	if (!s || !delimiter)
		return (NULL);
	words = word_ncount(s, delimiter, ft_strlen(s));
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
int	main(int c, char **v)
{
	char	*str;
	char	*sep;
	int		result;
	char	**arr;
	int		i;

	str = c > 1 ? v[1] : " Hello There ";
	sep = c > 2 ? v[2] : " ";
	result = word_ncount(str, sep, 1);
	printf("Str:%s\nSep: %s\nNum of Words: %d\nArray:\n", str, sep, result);
	arr = ft_split(str, sep);
	i = 0;
	while (i < result)
	{
		printf("%s\n", arr[i]);
		i++;
	}
	freen_arr((void **)arr);
}
*/
