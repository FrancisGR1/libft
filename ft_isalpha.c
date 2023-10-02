/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:57:59 by frmiguel          #+#    #+#             */
/*   Updated: 2023/09/10 14:33:37 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_alpha(char c)
{
	return (is_upper(c) || is_lower(c));
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_alpha(str[i]))
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
        char result1 = ft_str_is_alpha("oi") + '0';
        char result2 = ft_str_is_alpha("OlA---") + '0';

        write(1, &result1, 1);
        write(1, "\n", 1);
        write(1, &result2, 1);
}
*/
