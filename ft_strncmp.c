/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:06:48 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/07 21:53:57 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	char *str1 = c > 1 ? v[1] : "Hello World";
	char *str2 = c > 2 ? v[2] : "Hello There";
	int n = c > 3 ? atoi(v[3]) : 8;
	int result = ft_strncmp(str1, str2, n);
	printf("%s - %s = %d (n = %d)\n", str1 , str2, result, n);
	int result1 = strncmp(str1, str2, n);
	printf("%s - %s = %d (n = %d)\n", str1, str2, result1, n); 
	printf("Testing for null:\n");
	printf("ft strncmp:\n");
	int null_ft_res = ft_strncmp(NULL, str2, n);
	printf("res: %d\n", null_ft_res);
	printf("strncmp:\n");
	char *null_str = NULL;
	//should crash
	int null_str_res = strncmp(null_str, str2, n);
}
*/
