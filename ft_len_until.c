#include "libft.h"

size_t ft_len_until(char *s, char c)
{
	const char *ch_pos = (const char *)ft_strchr(s, c);

	if (ch_pos)
	{
		return ((size_t)(ch_pos - s));
	}
	return (ft_strlen(s));
}
