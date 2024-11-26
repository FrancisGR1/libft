#ifndef STRING_H
# define STRING_H

#include "../libft.h"

//types of safer strings
typedef enum e_str_type
{
	STR_NULL,
	STR_POINTER,
	STR_ALLOCATED,
}					t_str_type;

//safer strings
typedef struct s_string
{
	char			*s;
	char			*end;
	size_t			len;
	t_str_type		type;
}					t_string;

//TODO: organizar
//initialization
t_string			new_str(char *s, t_str_type type);
t_string			cstr_to_str_ptr(char *raw_str, int size);
t_string			cstr_to_str(char *raw_str);
t_string			cstr_to_str_nsize(char *raw_str, int size);
char				*string_convert_back(t_string str);

//find target in string
int					string_find(t_string str, size_t start, size_t n, char *delimiters);
t_string			string_find_word(t_string str, size_t start, t_string target);
struct s_dynamic_array		*string_findall(t_string str, char *delimiters);

//advance in the string
int					str_iter(t_string str, size_t start, size_t n,
						int (*iterator)(int c));
bool				str_advance_ptr(t_string *str);
bool				str_advance_ptr_ntimes(t_string *str, int n);

//manipulation
t_string			str_join(int strs_num, int strs_size, ...);
t_string			str_cat(t_string s1, t_string s2);
void				str_free_and_replace_raw(t_string *str, char *raw_str);
void				str_free_and_replace_str(t_string *str,
						t_string *substitute);
int					str_cmp(t_string s1, t_string s2, size_t s1_start);
t_string			str_dup(t_string to_duplicate);

//split
t_string			*string_split(t_string str, char *delimiters, int *len);
t_string			*string_split_dup(t_string str, char *delimiters, int *len);
t_string			*string_divide(t_string str, t_string dlim, int *len);
void				string_divide_in_two(t_string str,
						t_string divided_parts_buf[2], t_string dlim,
						int *num_of_parts);
//utils
bool				str_is_null(t_string str);
void				string_free(t_string *str);
bool				str_restore_state(t_string *to_restore, t_string original);
t_string			str_save_state(t_string to_save);
int					string_put(t_string s, int fd);

//array of strings
void				string_arr_free(t_string **strs);
t_string			*str_arr_dup(t_string *str_arr);
void				str_arr_deep_copy(t_string *dst, t_string *src, int size);
size_t				strs_count(t_string *args);

#endif /*STRING_H*/
