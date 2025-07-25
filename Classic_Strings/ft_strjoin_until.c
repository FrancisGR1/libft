/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_until.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:10:13 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:21 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

char	*ft_strjoin_until(char const *s1, char const *s2, char target)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!s2)
		return (0);
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (0);
	i = 0;
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		p[i + j] = s2[j];
		if (s2[j++] == target)
			break ;
	}
	p[i + j] = '\0';
	return (p);
}
