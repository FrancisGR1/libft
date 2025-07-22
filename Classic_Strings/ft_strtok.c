/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:14:45 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:25 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

//@TODO: reduzir linhas
char	*ft_strtok(char *s, const char *delim)
{
	static char	*saved_ptr;
	char		*end;

	if (s == NULL)
		s = saved_ptr;
	if (*s == '\0')
	{
		saved_ptr = s;
		return (NULL);
	}
	s += ft_strspn(s, delim);
	if (*s == '\0')
	{
		saved_ptr = s;
		return (NULL);
	}
	end = s + ft_strcspn(s, delim);
	if (*end == '\0')
	{
		saved_ptr = end;
		return (s);
	}
	*end = '\0';
	saved_ptr = end + 1;
	return (s);
}
