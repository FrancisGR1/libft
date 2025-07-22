/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:31:41 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:25 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

static int	get_len(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < start && s[i])
		i++;
	j = 0;
	while (j < len && s[i + j])
		j++;
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		p = malloc(1);
		if (!p)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	p = malloc(get_len(s, start, len) * sizeof(char) + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		p[i] = s[start++];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*
   int main(int c, char **v)
   {
   char *str = c > 1 ? v[1] : "Hello";
   int start = c > 2 ? atoi(v[2]) : 2;
   int len = c > 3 ? atoi(v[3]) : 5;
   int sizeToPass = get_len(str, start, len);
   char *result = ft_substr(str, start, len);
   char *wtf = "but why";
   printf("%s\n%d\n%s\n", str, sizeToPass, result != NULL ? result : wtf);
   }
 */
/*
   int main(int c, char **v)
   {
   char *str = c > 1 ? v[1] : "Hello";
   int start = c > 2 ? atoi(v[2]) : 2;
   int len = c > 3 ? atoi(v[3]) : 5;
   char *result = ft_substr(str, start, len);

   printf("Original string: %s\n", str); // Print the original string
   if (result)
   {
   printf("Result: %s\n", result); // Print the result if it's not NULL
   free(result); // Free the dynamically allocated memory
   }
   else
   printf("WTF");
   return (0);
   }
 */

/*
   I just want this part #############
   12345678912345678912
substr: |t want this part ###|
ft_substr: |t want this par|

 */
