/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:31:41 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:03:21 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classic_strings.h"

// Testing for failed malloc
/*
void	*mock_malloc(size_t size) {
	(void)size;
	return (NULL);
}
#define malloc(size) mock_malloc(size)

*/
char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s) + 1;
	ptr = (char *)malloc(size * sizeof(char));
	if (!ptr)
		ptr = 0;
	else
		ft_memcpy(ptr, s, size);
	return (ptr);
}
/*
int	main(void) {
	const char *originalString = "Hello, World!";
	char *duplicateString = ft_strdup(originalString);

	if (duplicateString != NULL) {
		printf("Original: %s\n", originalString);
		printf("Duplicate: %s\n", duplicateString);

		// Clean up memory
		free(duplicateString);
	} else {
		printf("Memory allocation failed. -> %p\n", duplicateString);
	}

	return (0);
}
*/
