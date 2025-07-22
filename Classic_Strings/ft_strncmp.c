/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:06:48 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:23 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (-1);
	while (*s1 && *s1 == *s2 && n)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/*
int main (int c, char **v)
{
	char	*str1;
	char	*str2;
	int		n;
	int		result;
	int		result1;
	int		null_ft_res;
	char	*null_str;
	int		null_str_res;

	str1 = c > 1 ? v[1] : "Hello World";
	str2 = c > 2 ? v[2] : "Hello There";
	n = c > 3 ? atoi(v[3]) : 8;
	result = ft_strncmp(str1, str2, n);
	printf("%s - %s = %d (n = %d)\n", str1 , str2, result, n);
	result1 = strncmp(str1, str2, n);
	printf("%s - %s = %d (n = %d)\n", str1, str2, result1, n);
	printf("Testing for null:\n");
	printf("ft strncmp:\n");
	null_ft_res = ft_strncmp(NULL, str2, n);
	printf("res: %d\n", null_ft_res);
	printf("strncmp:\n");
	null_str = NULL;
	//should crash
	null_str_res = strncmp(null_str, str2, n);
}
*/
