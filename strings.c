#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_string	new_str(char *s)
{
	t_string str;

	if (s == NULL)
	{
		str.s = NULL;
		str.end = NULL;
		str.len = 0;
	}
	else
	{
		str = cstr_to_str(s);	
	}
	return (str);
}

t_string cstr_to_str_ptr(char *raw_str, size_t size)
{
	t_string str;

	if (!raw_str || !size)
		return (new_str(NULL));
	str.len = size;
	str.s = raw_str;
	if (str.len > 0)
		str.end = str.s + str.len - 1;
	else
		str.end = str.s;
	return (str);
}

t_string cstr_to_str(char *raw_str)
{
	t_string str;

	if (!raw_str)
		return (new_str(NULL));
	str.len = ft_strlen(raw_str);
	str.s = (char *) malloc (str.len + 1);
	if (str.len > 0)
		str.end = str.s + str.len - 1;
	else
		str.end = str.s;
	if (ft_strlcpy(str.s, raw_str, str.len + 1) == 0)
		str.s[0] = '\0';
	return (str);
}

t_dynamic_array *string_findall(t_string str, char *delimiters)
{
	t_dynamic_array *ptrs;
	size_t i;
	size_t j;
	const t_string delims_ptr = cstr_to_str_ptr(delimiters, ft_strlen(delimiters));
	t_string tmp;

	ptrs = darr_init(sizeof(t_string));
	i = 0;
	while (i < str.len)
	{
		j = 0;
		while (j < delims_ptr.len)
		{
			if (str.s[i] == delims_ptr.s[j])
			{
				tmp = cstr_to_str_ptr(&str.s[i], 1);
				darr_append(ptrs, (const void *)&tmp);
			}
			j++;
		}
		i++;
	}
	if (!ptrs->len)
	{
		darr_free(ptrs);
		ptrs = NULL;
	}
	return (ptrs);
}

int string_find(t_string str, size_t start, size_t n, char *delimiters)
{
	size_t i;
	const t_string delims_ptr = cstr_to_str_ptr(delimiters, ft_strlen(delimiters));

	if (!str.s) 	
		return (-1);
	if (!delims_ptr.s)
		return (-1);
	while (start < str.len && n--)
	{	
		i = 0;
		while (i < delims_ptr.len)
		{
			if (str.s[start] == delims_ptr.s[i])
				return start;
			i++;
		}
		start++;
	}
	return (-1);

}

t_string *string_split(t_string str, char *delimiters)
{
	t_string *strs;
	size_t pos;
	size_t idx;
	size_t start;
	const t_string delims_ptr = cstr_to_str_ptr(delimiters, ft_strlen(delimiters));

	strs = malloc((word_count(str.s, delimiters) + 1) * sizeof(t_string));
	idx = 0;
	pos = 0;
	start = 0;
	while (idx < str.len)
	{
		while (idx < str.len && string_find(str, idx, 1, delims_ptr.s) != -1)
			idx++;
		start = idx;
		while (idx < str.len && string_find(str, idx, 1, delims_ptr.s) == -1)
			idx++;
		if (idx > start)
			strs[pos++] = cstr_to_str_ptr(str.s + start, idx - start);
		idx++;
	}
	if (!pos)
	{
		free(strs);
		return (NULL);
	}
	strs[pos] = new_str(NULL);
	return (strs);
}

int string_put(t_string s, int fd)
{
	if (!s.s)
		return write(fd, "(null)", 6);
	return write(fd, s.s, s.len);
}

//Example usage: string_split
/*
   int main(void)
   {
   char raw_str[40] = "|HELLO|||world|olol|||a|||";

   t_string *res = string_split(raw_str, "|");
// Free all allocated memory
ft_fprintf(OUT, "Delimiter: %S\n\nSplitted %s into:\n", "|", raw_str);
for (int i = 0; res[i].s; i++) {
ft_fprintf(OUT, "\n");
string_put(res[i],OUT);
ft_fprintf(OUT, "\n");
}
free(res);
}
*/

/*
//Example usage: string_findall
int main(void)
{
char *str_orig = "Ola| ola| || !! ola\n";
char *str = malloc(100);
ft_strlcpy(str, str_orig, 100);
t_string tmp = cstr_to_str_ptr(str, ft_strlen(str));
t_dynamic_array *res = string_findall(tmp, "|!");
printf("analyzing: %s\n", str);
for (size_t i = 0; i < res->len; i++)
{
t_string tmp = ((t_string *)res->data)[i];
ft_fprintf(OUT, "%d: %S ", (int) i, tmp);
long long int pos = tmp.s - str;
fprintf(stdout, "\t(%p %zu %lld)\n\n", &tmp.s, tmp.len, pos);
 *tmp.s = 'x';
 }
 printf("after: %s\n", str);
 darr_free(res);
 free(str);
 }
 */
