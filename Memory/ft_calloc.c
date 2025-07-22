/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:35:08 by francis           #+#    #+#             */
/*   Updated: 2025/07/22 17:15:16 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	bytes;

	if (!size || !nmemb)
		return (NULL);
	bytes = nmemb * size;
	p = malloc(bytes);
	if (!p)
		return (NULL);
	ft_memset(p, 0, bytes);
	return (p);
}
/*
   int main()
   {
   int *intArray = (int *)ft_calloc(0, sizeof(int));
   if (intArray != NULL) {
   for (int i = 0; i < 5; i++) {
   printf("%d ", intArray[i]); // Should print "0 0 0 0 0 "
   }
   free(intArray);
   }
   else
   printf("%p\n", intArray);

   double *doubleArray = (double *)ft_calloc(3, sizeof(double));
   if (doubleArray != NULL) {
   for (int i = 0; i < 3; i++) {
   printf("\n%lf  \n", doubleArray[i]);
   }
   free(doubleArray);
   }
   else
   printf("%p\n", intArray);

   return (0);
   }
 */
