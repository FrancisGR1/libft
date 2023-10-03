/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:01:37 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/03 12:16:10 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.a"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (*(s + (++i)));
	return (i);
}
/*
int	main(int c, char **v)
{
	int mine = ft_strlen(v[1]);
	int std = strlen(v[1i]);

	printf("%d\n%d\n", mine, std);	
}
*/
