/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:01:37 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:22 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = -1;
	while (*(s + (++i)))
		;
	return (i);
}
/*
int	main(int c, char **v)
{
	int	mine;
	int	std;

	mine = ft_strlen(v[1]);
	std = strlen(v[1]);
	printf("%d\n%d\n", mine, std);
}
*/
