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
	str.end = str.s + str.len;
	return (str);
}

t_string cstr_to_str(char *raw_str)
{
	t_string str;

	if (!raw_str)
		return (new_str(NULL));
	str.len = ft_strlen(raw_str);
	str.s = malloc(str.len + 1);
	str.end = str.s + str.len;
	ft_strlcpy(str.s, raw_str, str.len + 1); 
	return (str);
}

t_darr *string_findall(t_string str, t_string targets)
{
	t_darr *positions;
	size_t i;
	size_t j;

	positions = darr_init(sizeof(int));
	i = 0;
	int k = 0;
	while (i < str.len)
	{
		j = 0;
		while (j < targets.len)
		{
			if (str.s[i] == targets.s[j])
			{
				k++;
				ft_fprintf(OUT, "cnt: %d\n", k);
				darr_append(positions, &i);
			}
			j++;
		}
		i++;
	}
	return (positions);
}

int string_find(t_string str, size_t index, size_t n, t_string delimiters)
{
	size_t i;

	if (!str.s) 	
		return (-1);
	if (!delimiters.s)
		return (-1);
	while (index < str.len && n--)
	{	
		i = 0;
		while (i < delimiters.len)
		{
			if (str.s[index] == delimiters.s[i])
				return index;
			i++;
		}
		index++;
	}
	return (-1);

}

t_string *string_split(t_string str, t_string delimiters)
{
	t_string *strs;
	size_t pos;
	size_t idx;
	size_t start;

	strs = malloc((word_count(str.s, delimiters.s) + 1) * sizeof(t_string));
	idx = 0;
	pos = 0;
	start = 0;
	while (idx < str.len)
	{
		while (idx < str.len && string_find(str, idx, 1, delimiters) != -1)
			idx++;
		start = idx;
		while (idx < str.len && string_find(str, idx, 1, delimiters) == -1)
			idx++;
		if (idx > start)
		{
			ft_putns(str.s +start, idx - start);
			strs[pos++] = cstr_to_str_ptr(str.s + start, idx - start);
		}
		idx++;
	}
	strs[pos] = new_str(NULL);
	return (strs);
}

int string_put(t_string s, int fd)
{
	return write(fd, s.s, s.len);
}

//Example usage: string_split

/*
int main(void)
{
	char raw_str[40] = "|HELLO|||world|olol|||a|||";

	t_string new = cstr_to_str(raw_str);
	t_string delims = new_str("|");
	t_string *res = string_split(new, delims);
	// Free all allocated memory
	ft_fprintf(OUT, "Delimiter: %S\n\nSplitted %s into:\n", delims, raw_str);
	for (int i = 0; res[i].s; i++) {
		ft_fprintf(OUT, "\n");
		string_put(res[i],OUT);
		ft_fprintf(OUT, "\n");
	}
	free(res);
	free(delims.s);
	free(new.s);
}
*/
//Example usage: string_findall


/*int main(void)
{
	t_string str = new_str("\04\04ola    \04\04         ola2 ola3            ola\04\04");
	t_string delims = new_str("\04");
	t_darr *res = string_findall(str, delims);
	for (size_t i = 0; i < res->len; i++)
		ft_fprintf(OUT, "%d\n", ((int *)res->data)[i]);
	darr_free(res);
	free(delims.s);
	free(str.s);
}
*/
