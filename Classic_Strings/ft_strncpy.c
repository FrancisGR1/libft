#include "classic_strings.h"

char *ft_strncpy(char *dst, char *src, size_t n)
{
	char *ptr;

	if (dst == NULL || src == NULL || n == 0)
		return (NULL);	
	ptr = dst;
	while (*src != '\0' && n > 0)
	{
		*dst++ = *src++;
		n--;
	}
	*dst = '\0';
	return (ptr);
}
