/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:01 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:23 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H

# include "../libft.h"
# include "string_internals.h"

# define STRING_DEFAULT_CAPACITY 64
# define STRING_MEMORY_INITIAL_SIZE 2000

# define STRING_ASCII_LETTERS \
	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define STRING_ASCII_LOWERCASE "abcdefghijklmnopqrstuvwxyz"
# define STRING_ASCII_UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define STRING_DIGITS "0123456789"
# define STRING_HEXDIGITS "0123456789abcdefABCDEF"
# define STRING_WHITESPACE " \t\n\r\f\v"
# define STRING_PUNCTUATION "!\"#$%&'()*+,-./:;<?@[\\]^_`{|}~"

typedef struct s_string_memory	t_string_memory;

typedef struct s_string
{
	char						*data;
	size_t						size;
	size_t						capacity;
	t_string_memory				*memory;

}								t_string;

// creation
// @TODO: criar str_create_from_arena(const char *str_data,
// exemplo:	void (*alloc) (void *data), void *memory_region)
// @TODO: mudar malloc para alloc em todas as funções
// @TODO: criar str_dup
t_string						*str_create(const char *str_data);
t_string						**str_create_from_multiple(size_t count, ...);

// destruction
bool							str_deallocate(t_string *str);
bool							str_array_deallocate(t_string **arr_of_strs,
									size_t count);
bool							str_clear(t_string *str);
void							str_deallocate_interface(void *ptr);

// convert
// - from primitive types
t_string						*str_from_int(int value);
// - to primitive types
int								str_to_int(const t_string *str);

// size, capacity
size_t							str_length(const t_string *str);
size_t							str_capacity(const t_string *str);
size_t							str_max_size(void);
bool							str_empty(const t_string *str);

// insert
void							str_append(t_string *str, const char *str_item);
void							str_push_back(t_string *str,
									const char ch_item);
void							str_insert(t_string *str, size_t pos,
									const char *str_item);
void							str_assign(t_string *str, const char *new_str);

// replace
void							str_replace(t_string *str1, const char *old_str,
									const char *new_str);
void							str_replace_all(t_string *str,
									const char *old_str, const char *new_str);

// substring
t_string						*str_substr(t_string *str, size_t pos,
									size_t len);
size_t							str_count(const t_string *str,
									const char *substr);

// copy
size_t							str_copy(const t_string *str, char *buffer,
									size_t pos, size_t len);

// split
t_string						**str_split_using_char_as_delim(
									const t_string *str,
									const char *delimiters, int *count);
t_string						**str_split_using_str_as_delim(
									const t_string *str,
									const char *delimiter, int *count);

// join
t_string						*str_join(t_string **strings, int count,
									const char *delimiter);
t_string						*str_join_variadic(size_t count, ...);

// search
int								str_find(const t_string *str,
									const char *buffer, size_t pos);
int								str_rfind(const t_string *str,
									const char *buffer, size_t pos);
int								str_find_first_of(const t_string *str,
									const char *buffer, size_t pos);
int								str_find_last_of(const t_string *str,
									const char *buffer, size_t pos);
int								str_find_first_not_of(const t_string *str,
									const char *buffer, size_t pos);
int								str_find_last_not_of(const t_string *str,
									const char *buffer, size_t pos);

// match
bool							str_contains(const t_string *str,
									const char *substr);
bool							str_starts_with(const t_string *str,
									const char *substr);
bool							str_ends_with(const t_string *str,
									const char *substr);

// compare
int								str_compare(const t_string *str1,
									const t_string *str2);
int								str_compare_ignore_case(const t_string *str1,
									const t_string *str2);

// arithmetics
bool							str_is_equal(const t_string *str1,
									const t_string *str2);
bool							str_is_not_equal(const t_string *str1,
									const t_string *str2);
bool							str_is_less(const t_string *str1,
									const t_string *str2);
bool							str_is_greater(const t_string *str1,
									const t_string *str2);

// is
bool							str_is_alpha(const t_string *str);
bool							str_is_digit(const t_string *str);
bool							str_is_only_this(const t_string *str,
									bool (*f)(char));
bool							str_is_alnum(const t_string *str);
bool							str_is_lower(const t_string *str);
bool							str_is_upper(const t_string *str);
bool							str_is_space(const t_string *str);
bool							str_is_printable(const t_string *str);

// remove
void							str_erase(t_string *str, size_t pos,
									size_t len);
void							str_erase_if(t_string *str,
									int (*should_remove)(int c),
									size_t start_pos);
void							str_pop_back(t_string *str);
void							str_remove(t_string *str, const char *substr);
void							str_remove_range(t_string *str,
									size_t start_pos, size_t end_pos);

// trim
void							str_trim(t_string *str);
void							str_trim_left(t_string *str);
void							str_trim_right(t_string *str);
void							str_trim_characters(t_string *str,
									const char *chars);

// case
char							*str_to_upper(const t_string *str);
char							*str_to_lower(const t_string *str);
void							str_to_title(t_string *str);
void							str_to_capitalize(t_string *str);
void							str_to_casefold(t_string *str);

// modify size
void							str_resize(t_string *str, size_t new_size);
void							str_reserve(t_string *str, size_t new_capacity);
void							str_shrink_to_fit(t_string *str);
bool							str_set_memory_size(t_string *str,
									size_t new_size);

// accessors
char							str_at(const t_string *str, size_t index);
const char						*str_c_str(const t_string *str);
char							*str_end(const t_string *str);
char							*str_begin(const t_string *str);

#endif /*STRINGS_H*/
