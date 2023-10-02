/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:38:13 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/02 18:19:36 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

/*
int	main()
{
	char str[] = "HELLO";
	char str2[] = "HeLLo";

	ft_strlowcase(str);
	ft_strlowcase(str2);

	write(1, &str, 5);
	write(1, "\n", 2);
	write(1, &str2, 5);

	return 0;
}*/
