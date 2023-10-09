/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:21:23 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/10 00:06:17 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char delimiter)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == delimiter)
			i++;
		if (s[i] && s[i] != delimiter)
			count++;
		while (s[i] && s[i] != delimiter)
			i++;
	}
	return (count);
}
/*
static char	free_arr(char **arr, int index)
{
	while (index >= 0)
	{
		free(arr[index]);
		arr[index] = NULL;
		index--;
	}
	arr = NULL;
	return (arr);
}
*/

static char	*ft_strndup(const char *s, size_t size)
{
	char	*ptr;

	ptr = (char *)malloc((size + 1) * sizeof(char));
	if (!ptr)
	{
		return (NULL);
	}
	ft_memcpy(ptr, s, size);
	ptr[size] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		i;
	int		j;
	int		k;
	char	**p;

	words = word_count(s, c);
	p = malloc((1 + words) * sizeof(char *));
	if (!p)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] && k < words)
	{
		j = i;
		while (s[j] && s[j] != c)
			j++;
		if (j > i)
			p[k++] = ft_strndup(s + i, j - i);
			if !(p[k])
				ft_strndup(s+i, j - i);
		i = j;
		i++;
	}
	p[k] = NULL;
	return (p);
}
/*
   int main(int c, char **v)
   {
   char *str = c > 1 ? v[1] : " Hello There ";
   char sep = c > 2 ? v[2][0] : ' ';
   int result = count_words(str, sep);
   printf("Str:%s\nSep: %c\nNum of Words: %d\nArray:\n", str, sep, result);
   char	**arr = ft_split(str, sep);
   int i = 0;
   while (i < result)
   {
   printf("%s\n", arr[i]);
   i++;
   }
   }
 */
