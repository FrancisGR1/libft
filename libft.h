/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:20:37 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 16:14:36 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <ctype.h>
# include <errno.h>
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

# include "Memory/memory.h"
# include "Strings/strings.h"
# include "Checkers/checkers.h"
# include "Classic_Strings/classic_strings.h"
# include "Math/math.h"
# include "Write/write.h"
# include "Files/files.h"
# include "Data_Structures/Dynamic_Arrays/dynamic_array.h"
# include "Data_Structures/Lists/lists.h"
# include "Data_Structures/Queues/queues.h"
# include "Arena/arena.h"
# include "Data_Structures/Hash_Table/hash_table.h"
# include "colors.h"

// insert memory debuggers
//
/*
# if defined DEBUG_REPLACE && DEBUG_REPLACE == 1
void				*debug_malloc(size_t size, const char *file, int line);
void				debug_free(void *ptr, const char *file, int line);
#  define malloc(size) debug_malloc(size, __FILE__, __LINE__)
#  define free(ptr) debug_free(ptr, __FILE__, __LINE__)
# endif
*/

# define YES 1
# define TRUE 1
# define NO 0
# define FALSE 0

# define STDOUT STDOUT_FILENO
# define STDIN STDIN_FILENO
# define STDERR STDERR_FILENO

#endif
