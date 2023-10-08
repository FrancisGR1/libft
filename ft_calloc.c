/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:35:08 by francis           #+#    #+#             */
/*   Updated: 2023/10/08 18:32:48 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*p;
	size_t			i;
	unsigned char	*ptr;

	if (!size || !nmemb)
	{
		p = malloc(0);
		return (p);
	}
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ptr = p;
	i = 0;
	while (i < nmemb * size)
		ptr[i++] = 0;
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

   return 0;
   }
 */