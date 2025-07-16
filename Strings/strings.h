#ifndef STRINGS_H
# define STRINGS_H

#include "../libft.h"

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

} t_string;

#endif /*STRINGS_H*/
