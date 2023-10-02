/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:38:59 by frmiguel          #+#    #+#             */
/*   Updated: 2023/09/10 12:55:42 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
int main()
{
	char result1 = ft_str_is_printable(" ") + '0';
	char result2 = ft_str_is_printable("~") + '0';

	write(1, &result1, 1);
	write(1, "\n", 1);
	write(1, &result2, 1);

	return (0);
}*/
