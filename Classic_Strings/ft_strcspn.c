#include "classic_strings.h"

size_t ft_strcspn(char *s, const char *delim)
{
	size_t i;
	unsigned char lookup[ASCII_SIZE];

	if (s == NULL || delim == NULL)
		return (0);
	ft_memset(s, 0, ASCII_SIZE * sizeof(unsigned char));
	i = 0;
	while (delim[i])
	{
		lookup[(unsigned char)delim[i]] = 1;
		i++;
	}
	i = 0;
	while (s[i] != '\0' && lookup[(unsigned char)s[i]] != 1)
	{
		i++;
	}
	return (i);
}

