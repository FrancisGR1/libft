/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:30:10 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:15:16 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		*ptr = 0;
		ptr++;
		i++;
	}
}
/*
int	main(void)
{
	int		n;
	char	arr[] = "test";
	char	arr1[] = "test";
	int		i;

	n = 4;
	i = 0;
	ft_bzero(arr, 5);
	bzero(arr1, 5);
	printf("MINE:%s", arr);
	while (i < n)
	{
		printf("%d", arr[i]);
		i++;
	}
	i = 0;
	printf("\nSTD:");
	while (i < n)
	{
		printf("%d", arr1[i]);
		i++;
	}
	printf("\n");
}
*/
