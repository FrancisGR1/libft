/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:38:59 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/03 12:13:06 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.a"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	else
		return (0);
}

int main(int c, char **v)
{
	int mine = ft_isprint(atoi(v[1]));
	int std = isprint(atoi(v[1]));
	
	int mine2 = ft_isprint('\n');
	int std2 = isprint('\n');

	printf("Arg:\n%d\n%d\nLetters:\n%d\n%d\n", mine, std, mine2, std2);
	return (0);
}
