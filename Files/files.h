/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:13:41 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:39:15 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

# include "../libft.h"

# define MAX_FDS 1000

// Forward declaration to avoid a circular dependency with strings.h
typedef struct s_string	t_string;

// get next line structure
// mostly for convenience
typedef struct s_line_str
{
	char				*old;
	char				*new;
	bool				nl;
}						t_line;

char					*get_next_line(int fd);
t_string				*get_next_line_to_str(int fd);
int						ft_getc(int fd);

#endif /*FILES_H*/
