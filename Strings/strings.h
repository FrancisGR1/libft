#ifndef STRINGS_H
# define STRINGS_H

#include "string_internals.h"
#include "../libft.h"

#define STRING_DEFAULT_CAPACITY 64
// 1kb for each string
#define STRING_MEMORY_INITIAL_SIZE 10000000
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
t_string *str_create_from_global_memory(size_t size);
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

#endif /*STRINGS_H*/
