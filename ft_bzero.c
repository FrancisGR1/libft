/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:30:10 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/03 18:05:24 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t		i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		*ptr = '\0';
		ptr++;
		i++;
	}


}
//output estranho:
//ft_bzero: 000NNNNNNN
//bzero: 00000000N0

/*
int main(void)
{
	int n = 10;
	int arr[10] = {2,2,2,2,2,2,2,2,2,2};
	int arr1[10] = {2,2,2,2,2,2,2,2,2,2};
	int	i = 0;

	ft_bzero(arr, n);
	bzero(arr1, n);
	while (i < 10)
	{
		if (arr[i] == 0)
			printf("0");
		else
			printf("N");
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 10)
	{
		if (arr1[i] == 0)
			printf("0");
		else
			printf("N");
		i++;
	}
	printf("\n");	
}*/
