#include "classic_strings.h"

char *strtok(char *s, const char *delim)
{
	static char *saved_ptr;
	char *end;

	if (s == NULL)
		s = saved_ptr;
	if (*s == '\0')
	{
		saved_ptr = s;
		return NULL;
	}
	s += ft_strspn(s, delim);
	if (*s == '\0')
	{
		saved_ptr = s;
		return NULL;
	}
	end = s + ft_strcspn(s, delim);
	if (*end == '\0')
	{
		saved_ptr = end;
		return (s);
	}
	*end = '\0';
	saved_ptr = end + 1;
	return (s);
}
