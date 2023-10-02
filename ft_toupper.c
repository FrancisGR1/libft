/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:19:55 by frmiguel          #+#    #+#             */
/*   Updated: 2023/09/10 13:55:50 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
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
        char result1 = ft_str_is_uppercase("a") + '0';
        char result2 = ft_str_is_uppercase("A") + '0';

        write(1, &result1, 1);
        write(1, "\n", 2);
        write(1, &result2, 1);

	return (0);
}
*/
