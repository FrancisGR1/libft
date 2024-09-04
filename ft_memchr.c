/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:08:37 by frmiguel          #+#    #+#             */
/*   Updated: 2023/10/30 15:19:44 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		uc;
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (n)
	{
		if (*ptr == uc)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
/*
int main(void)
{
	//teste para clean_line (em get_next_line)
	char *test = "a\nb";
	char *result = ft_memchr(test, 'b', 20);
	if (!(result))
		printf("NOPE");
	else if (!(*(result + 1)))
		printf("NOPE + 1");
	else
		printf("%s", result + 1);		
}
*/
