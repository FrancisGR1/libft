/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:57:20 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:23 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		len;
	int		i;

	len = ft_strlen(s);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
char	uppercase(unsigned int index, char c)
{
	if (c >= 'a' && c <= 'z') {
		return (c - ('a' - 'A'));
	}
	return (c);
}
char	evenIndexToAsterisk(unsigned int index, char c) {
	if (index % 2 == 0) {
		return ('*');
	}
	return (c);
}
*/
/*
int	main(void) {
	char input[] = "Hello, World!";

	char *result1 = ft_strmapi(input, uppercase);
	char *result3 = ft_strmapi(input, evenIndexToAsterisk);

	// Should print "HELLO, WORLD!"
	printf("uppercase(): %s\n", result1);
	// Should print "*e*l*, W*r*d!"
	printf("evenIndexToAsterisk(): %s\n", result3);

	free(result1);
	free(result3);

	return (0);
}
*/
