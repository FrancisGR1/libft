#include "safer_strings.h"

void	string_free(t_string *str)
{
	if (!str || str_is_null(*str) || str->type != STR_ALLOCATED)
		return ;
	if (str->s)
		free(str->s);
	*str = new_str(NULL, 0);
}

int	string_put(t_string s, int fd)
{
	if (str_is_null(s))
		return (write(fd, "(null)", 6));
	return (write(fd, s.s, s.len));
}

bool	str_is_null(t_string str)
{
	return (!str.s || str.type == STR_NULL);
}

t_string	str_save_state(t_string to_save)
{
	t_string	str;

	str.s = to_save.s;
	str.end = to_save.end;
	str.len = to_save.len;
	return (str);
}

bool	str_restore_state(t_string *to_restore, t_string original)
{
	if (!to_restore || str_is_null(*to_restore))
		return (false);
	to_restore->s = original.s;
	to_restore->end = original.end;
	to_restore->len = original.len;
	return (true);
}
