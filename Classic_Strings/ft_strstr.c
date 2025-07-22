/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:26:11 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:25 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	if (ft_strcmp(little, "") == 0 || *little == '\0')
		return ((char *)big);
	j = 0;
	while (*big)
	{
		i = 0;
		while (big[i] && big[i] == little[i] && little[i])
		{
			if (!little[i + 1])
				return ((char *)big);
			i++;
		}
		big++;
		j++;
	}
	return (NULL);
}
