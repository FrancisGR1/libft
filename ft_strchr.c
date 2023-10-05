#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*(ptr))
	{
		if (*ptr == c)
			return (ptr);
		ptr++;

	}
	return (NULL);
}

/*
int main(int c, char **v)
{
	char *str = c > 1 ? v[1] : "What a crazy world";
	char l = c > 2 ? v[2][0] : 'c';
	printf("ft_strchr: %s --> %p\n", ft_strchr(str, l), (void *)ft_strchr(str, l));
	printf("strchr: %s --> %p\n", strchr(str, l), (void *)strchr(str, l));
}
*/
