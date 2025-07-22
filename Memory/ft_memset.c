/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:17:05 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:15:18 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	if (!s)
		return (NULL);
	ptr = (unsigned char *)s;
	i = -1;
	while (++i < n)
		*(ptr + i) = c;
	return (s);
}
/*
   void printArray(int arr[], int n)
   {
   for (int i=0; i<n; i++)
   printf("%d ", arr[i]);
   }

   int main(void)
   {
   printf("CHAR\n");
   char str[50] = "GeeksForGeeks is for programming geeks.";
   char str1[50] = "GeeksForGeeks is for programming geeks.";
   printf("Before memset: %s", str);
   printf("\nBefore memset: %s", str1);

   memset(str + 13, '.', 8*sizeof(char));
   ft_memset(str1 + 13, '.', 8*sizeof(char));

   printf("\nAfter memset: %s", str);
   printf("\nAfter memset: %s\n", str1);

   printf("\n\n\t ---\n\n");

   int n = 10;
   int arr2[n];
   int arr3[n];
   printf("Array before memset()\n");
   memset(arr2, 0, n*sizeof(arr2[0]));
   ft_memset(arr3, 0, n*sizeof(arr3[0]));
   printArray(arr2, n);
   printf("\n");
   printArray(arr3, n);
   printf("\n");

   printf("Array after memset()\n");
   memset(arr2, 1, n*sizeof(arr2[0]));
   ft_memset(arr3, 1, n*sizeof(arr3[0]));
   printArray(arr2, n);
   printf("\n");
   printArray(arr3, n);
   printf("\n");
   return (0);


   }
 */
/*https://www.geeksforgeeks.org/unsigned-char-in-c-with-examples*/
