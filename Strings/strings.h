#ifndef STRINGS_H
# define STRINGS_H

#include "string_internals.h"
#include "../libft.h"

#define STRING_DEFAULT_CAPACITY 64
// 1kb for each string
#define STRING_MEMORY_INITIAL_SIZE 10000000
//@TODO: alterar nome com "STRING" como prefixo
#define MAX_STRING_SIZE (SIZE_MAX / 2)

#define STRING_ASCII_LETTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define STRING_ASCII_LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define STRING_ASCII_UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define STRING_DIGITS "0123456789"
#define STRING_HEXDIGITS "0123456789abcdefABCDEF"
#define STRING_WHITESPACE " \t\n\r\f\v"
#define STRING_PUNCTUATION "!\"#$%&'()*+,-./:;<?@[\\]^_`{|}~"

typedef struct s_string
{
	char *data;
	size_t size;
	size_t capacity;
	t_string_memory *memory;

} t_string;

// creation
t_string *str_create(const char* str_data);
t_string **str_create_from_multiple(size_t count, ...);

// destruction
bool str_deallocate(t_string *str);
bool str_clear(t_string* str);

// convert
// - from primitive types
t_string *str_from_int(int value);
t_string *str_from_float(float value);
t_string *str_from_double(double value);
// - to primitive types
int str_to_int(const t_string *str);
float str_to_float(const t_string *str);
double str_to_double(const t_string* str);

// size, capacity
size_t str_length(const t_string* str);
size_t str_capacity(const t_string* str);
size_t str_max_size(void);
bool str_empty(const t_string* str);

// insert
void str_append(t_string* str, const char* str_item);
void str_push_back(t_string* str, const char ch_item);
void str_insert(t_string* str, size_t pos, const char* str_item);
void str_assign(t_string *str, const char *new_str);

// replace
void str_replace(t_string* str1, const char* old_str, const char* new_str);
void str_replace_all(t_string *str, const char *old_str, const char *new_str);

// substring
t_string* str_substr(t_string* str, size_t pos, size_t len);
size_t str_count(const t_string* str, const char* substr);

// split
t_string **str_split_using_char_as_delim(const t_string* str, const char* delimiters, int *count);
t_string **str_split_using_str_as_delim(const t_string *str, const char *delimiter, int *count);

// join
t_string* str_join(t_string **strings, int count, const char *delimiter);
t_string* str_join_variadic(size_t count, ...);

// search
int str_find(const t_string* str, const char* buffer, size_t pos);
int str_rfind(const t_string* str, const char* buffer, size_t pos);
int str_find_first_of(const t_string* str, const char* buffer, size_t pos);
int str_find_last_of(const t_string* str, const char* buffer, size_t pos);
int str_find_first_not_of(const t_string* str, const char* buffer, size_t pos);
int str_find_last_not_of(const t_string* str, const char* buffer, size_t pos);

// compare
int str_compare(const t_string* str1, const t_string* str2);
int str_compare_ignore_case(const t_string* str1, const t_string* str2);

// arithmetics
bool str_is_equal(const t_string* str1, const t_string* str2);
bool str_is_not_equal(const t_string* str1, const t_string* str2);
bool str_is_less(const t_string* str1, const t_string* str2);
bool str_is_greater(const t_string* str1, const t_string* str2);

// remove
void str_erase(t_string* str, size_t pos, size_t len);
void str_pop_back(t_string* str);
void str_remove(t_string* str, const char* substr);
void str_remove_range(t_string* str, size_t start_pos, size_t end_pos);

// trim
void str_trim(t_string *str);
void str_trim_left(t_string *str);
void str_trim_right(t_string *str);
void str_trim_characters(t_string* str, const char* chars);

// case
char* str_to_upper(const t_string* str);
char* str_to_lower(const t_string* str);
void str_to_title(t_string* str);
void str_to_capitalize(t_string* str);
void str_to_casefold(t_string* str);

// modify size
void str_resize(t_string* str, size_t new_size);
void str_reserve(t_string *str, size_t new_capacity);
void str_shrink_to_fit(t_string* str);
bool str_set_memory_size(t_string* str, size_t new_size);

//

#endif /*STRINGS_H*/
