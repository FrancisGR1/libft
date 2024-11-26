#ifndef FILES_H
# define FILES_H

#include "../libft.h"

//get next line structure
//mostly for convenience
typedef struct s_line_str
{
	char	*old;
	char	*new;
	bool	nl;
}			t_line;

char				*get_next_line(int fd);
int					ft_getc(int fd);

#endif /*FILES_H*/
