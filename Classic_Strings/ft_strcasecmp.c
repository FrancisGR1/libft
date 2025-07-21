#include "classic_strings.h"

int ft_strcasecmp(const char *s1, const char *s2)
{
	const unsigned char *p1;
	const unsigned char *p2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (-1);
	if (s2 == NULL)
		return (1);
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (*p1 != '\0' && ft_tolower(*p1) == ft_tolower(*p2))
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);

}
