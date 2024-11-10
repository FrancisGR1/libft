#include "libft.h"

t_string	new_str(char *s, t_str_type type)
{
	t_string str;

	if (s == NULL)
	{
		str.s = NULL;
		str.end = NULL;
		str.len = 0;
		str.type = STR_NULL;
	}
	else
	{
		str = cstr_to_str(s);	
		str.type = type;
	}
	return (str);
}

bool str_is_null(t_string str)
{
	return (!str.s || str.type == STR_NULL);
}

t_string cstr_to_str_ptr(char *raw_str, int size)
{
	t_string str;

	if (!raw_str || size < 0)
		return (new_str(NULL, 0));
	str.type = STR_POINTER;
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
		return (new_str(NULL, 0));
	str.len = ft_strlen(raw_str);
	str.s = (char *) malloc(str.len + 1);
	str.type = STR_ALLOCATED;
	if (str.len > 0)
		str.end = str.s + str.len - 1;
	else
		str.end = str.s;
	if (ft_strlcpy(str.s, raw_str, str.len + 1) == 0)
		str.s[0] = '\0';
	return (str);
}

t_string cstr_to_str_nsize(char *raw_str, int size)
{
	t_string str;

	if (!raw_str || size < 0)
		return (new_str(NULL, 0));
	str.len = size;
	str.s = (char *) malloc(str.len + 1);
	str.type = STR_ALLOCATED;
	if (str.len > 0)
		str.end = str.s + str.len - 1;
	else
		str.end = str.s;
	if (ft_strlcpy(str.s, raw_str, str.len + 1) == 0)
		str.s[0] = '\0';
	return (str);
}

t_string str_join(int strs_num, int strs_size, ...)
{
	va_list args;
	t_string res;
	t_string current;

	va_start(args, strs_size);
	res.s = malloc(strs_size + 1);
	res.type = STR_ALLOCATED;
	res.len = 0;
	while (strs_num)
	{
		current = va_arg(args, t_string);
		ft_strlcpy(res.s + res.len, current.s, current.len + 1);
		res.len += current.len;
		strs_num--;
	}
	res.s[res.len] = '\0';
	va_end(args);
	return (res);
}

t_string str_cat(t_string s1, t_string s2)
{
	t_string res;

	if (str_is_null(s1) && str_is_null(s2))
		return (new_str(NULL, 0));
	if (str_is_null(s1)) 
		return (s2);
	if (str_is_null(s2)) 
		return (s1);
	res.len = s1.len + s2.len;
	res.s = malloc(res.len + 1);
	if (!res.s)
		return (new_str(NULL, 0));
	res.type = STR_ALLOCATED;
	if (ft_strlcpy(res.s, s1.s, s1.len + 1) == 0)
		res.s[0] = '\0';
	if (ft_strlcat(res.s, s2.s, res.len + 1) == 0)
		res.s[s1.len] = '\0';
	res.end = res.s + s1.len + s2.len;
	return (res);
}

void str_free_and_replace_raw(t_string *str, char *raw_str)
{
	if (!str || str_is_null(*str))
		return ;
	if (str->type == STR_ALLOCATED)
		string_free(str);
	*str = cstr_to_str(raw_str);
}

void str_free_and_replace_str(t_string *str, t_string *substitute)
{
	if (!str || str_is_null(*str))
		return ;
	if (str->type == STR_ALLOCATED)
		string_free(str);
	*str = *substitute; 
}

t_dynamic_array *string_findall(t_string str, char *delimiters)
{
	const t_string delims_ptr = cstr_to_str_ptr(delimiters, ft_strlen(delimiters));
	t_dynamic_array *ptrs;
	size_t i;
	size_t j;
	t_string s;

	ptrs = darr_init(sizeof(t_string));
	i = 0;
	while (i < str.len)
	{
		j = -1;
		while (++j < delims_ptr.len)
		{
			s = cstr_to_str_ptr(&str.s[i], 1);
			if (str.s[i] == delims_ptr.s[j])
				darr_append(ptrs, (const void *)&s);
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

int str_iter(t_string str, size_t start, size_t n, int (*iterator)(int c))
{
	if (str_is_null(str))
		return (-1);
	while (iterator(str.s[start]) && n)
	{
		start++;
		n--;
	}
	return (start);
}

bool str_advance_ptr(t_string *str)
{
	if (!str || str_is_null(*str) || str->s == str->end)
		return (false);
	str->s++;
	str->len--;
	return (true);
}

bool str_advance_ptr_ntimes(t_string *str, int n)
{
	t_string original_str;

	original_str = str_save_state(*str);
	while (n)
	{
		if (!str_advance_ptr(str))
		{
			str_restore_state(str, original_str);
			return (false);
		}
		n--;
	}
	return (true);
}

t_string str_save_state(t_string to_save)
{
	t_string str;

	str.s = to_save.s;
	str.end = to_save.end;
	str.len = to_save.len;
	return (str);
}

bool str_restore_state(t_string *to_restore, t_string original)
{
	if (!to_restore || str_is_null(*to_restore))
		return (false);
	to_restore->s = original.s;
	to_restore->end = original.end;
	to_restore->len = original.len;
	return (true);
}

int string_find(t_string str, size_t start, size_t n, char *delimiters)
{
	const t_string delims_ptr = cstr_to_str_ptr(delimiters, ft_strlen(delimiters));
	size_t i;

	if (str_is_null(str) || str_is_null(delims_ptr)) 	
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

t_string string_find_word(t_string str, size_t start, t_string target)
{
	t_string res;

	res = new_str(NULL, 0);
	if (str_is_null(str) || str_is_null(target))
		return (res);
	while (start < str.len)
	{
		if (str_cmp(str, target, start) == 0)
		{
			res = cstr_to_str_ptr(&str.s[start], target.len);
			break;
		}
		start++;
	}
	return (res);
}

//delimiters are chars
t_string *string_split(t_string str, char *delimiters, int *len)
{
	const t_string delims_ptr = cstr_to_str_ptr(delimiters, ft_strlen(delimiters));
	t_string *strs;
	size_t idx;
	size_t start;

	strs = malloc((word_ncount(str.s, delims_ptr.s, str.len) + 1) * sizeof(t_string));
	idx = -1;
	*len = 0;
	start = 0;
	while (++idx < str.len)
	{
		while (idx < str.len && string_find(str, idx, 1, delims_ptr.s) != -1)
			idx++;
		start = idx;
		while (idx < str.len && string_find(str, idx, 1, delims_ptr.s) == -1)
			idx++;
		if (idx > start)
			strs[(*len)++] = cstr_to_str_ptr(str.s + start, idx - start);
	}
	if (!*len)
		return (free(strs), NULL);
	strs[*len] = new_str(NULL, 0);
	return (strs);
}

t_string *string_split_dup(t_string str, char *delimiters, int *len)
{
	const t_string delims_ptr = cstr_to_str_ptr(delimiters, ft_strlen(delimiters));
	t_string *strs;
	size_t idx;
	size_t start;

	strs = malloc((word_ncount(str.s, delims_ptr.s, str.len) + 1) * sizeof(t_string));
	idx = 0;
	*len = 0;
	start = 0;
	while (idx < str.len)
	{
		while (idx < str.len && string_find(str, idx, 1, delims_ptr.s) != -1)
			idx++;
		start = idx;
		while (idx < str.len && string_find(str, idx, 1, delims_ptr.s) == -1)
			idx++;
		if (idx > start)
			strs[(*len)++] = str_dup(cstr_to_str_ptr(str.s + start, idx - start));
		idx++;
	}
	if (!*len)
		return (free(strs), NULL);
	strs[*len] = new_str(NULL, 0);
	return (strs);
}

size_t strs_count(t_string *args)
{
	size_t i;

	if (!args)
		return (0);
	i = 0;
	while (args[i].s)
		i++;
	return(i);
}

int str_cmp(t_string s1, t_string s2, size_t s1_start)
{
	size_t i;

	i = 0;
	while (s1.s[s1_start] == s2.s[i] && s1_start < s1.len && i < s2.len)
	{
		s1_start++;
		i++;
	}
	return (s1.s[s1_start] - s2.s[i]);
}

t_string str_dup(t_string to_duplicate)
{
	t_string dup;
	int copied_chars;

	if (str_is_null(to_duplicate))
		return (new_str(NULL, 0));
	dup.len = to_duplicate.len;
	dup.s = malloc(dup.len + 1);
	dup.type = STR_ALLOCATED;
	copied_chars = ft_strlcpy(dup.s, to_duplicate.s, dup.len + 1);
	if (!copied_chars)
		dup.s[0] = '\0';
	dup.end = dup.s + copied_chars;
	return (dup);
}

//delimiter is a word
t_string *string_divide(t_string str, t_string dlim, int *len)
{
	t_string *strs;
	size_t idx;
	size_t start;

	strs = malloc((word_ncount(str.s, dlim.s, dlim.len) + 1) * sizeof(t_string));
	idx = 0;
	start = 0;
	*len = 0;
	while (idx < str.len)
	{
		if (str_cmp(str, dlim, idx) == 0)
			idx += dlim.len;
		start = idx;
		while (idx < str.len && str_cmp(str, dlim, idx) != 0)
			idx++;
		if (idx > start)
			strs[(*len)++] = cstr_to_str_ptr(str.s + start, idx - start);
		idx++;
	}
	if (!*len)
		return (free(strs), NULL);
	strs[*len] = new_str(NULL, 0);
	return (strs);
}

void string_divide_in_two(t_string str, t_string divided_parts_buf[2], t_string dlim, int *num_of_parts)
{
    size_t idx;
    size_t start;
    
    idx = 0;
    start = 0;
    *num_of_parts = 0;
    divided_parts_buf[0] = new_str(NULL, 0);
    divided_parts_buf[1] = new_str(NULL, 0);
    if (str_cmp(str, dlim, idx) == 0)
        idx += dlim.len;
    start = idx;
    while (idx < str.len && str_cmp(str, dlim, idx) != 0)
        idx++;
    if (idx > start) 
    {
        divided_parts_buf[0] = cstr_to_str_ptr(str.s + start, idx - start);
        *num_of_parts = 1;
    }
    if (idx < str.len) 
    {
        divided_parts_buf[1] = cstr_to_str_ptr(str.s + idx + dlim.len, str.len - idx - dlim.len);
        if (divided_parts_buf[1].len > 0)
            *num_of_parts = 2;
    }
}

char *string_convert_back(t_string str)
{
	char *s;

	if (str_is_null(str))
		return (NULL);
	s = malloc(str.len + 1);
	if (!s)
		return (NULL);
	if (ft_strlcpy(s, str.s, str.len + 1) == 0)
		s[0] = '\0';
	return (s);
}

int string_put(t_string s, int fd)
{
	if (str_is_null(s))
		return write(fd, "(null)", 6);
	return write(fd, s.s, s.len);
}

void string_free(t_string *str)
{
	if (!str || str_is_null(*str) || str->type != STR_ALLOCATED)
		return ;
	if (str->s)
		free(str->s);
	*str = new_str(NULL, 0);
}

void string_arr_free(t_string **strs)
{
	t_string *ptr;

	if (!strs || !*strs)
		return ;
	ptr = *strs;
	while (ptr && !str_is_null(*ptr))
	{
		string_free(ptr);
		ptr++;
	}
	free(*strs);
	*strs = NULL;
}

t_string *str_arr_dup(t_string *str_arr)
{
	size_t cnt;
	t_string *str_arr_dup;

	if (!str_arr)
		return (NULL);
	cnt = 0;
	while (str_arr[cnt].s)
		cnt++;
	str_arr_dup = ft_calloc(cnt + 1, sizeof(t_string));
	cnt = 0;
	while (str_arr[cnt].s)
	{
		str_arr_dup[cnt] = str_dup(str_arr[cnt]);
		cnt++;
	}
	str_arr_dup[cnt] = new_str(NULL, 0);
	return (str_arr_dup);

}

void str_arr_deep_copy(t_string *dst, t_string *src, int size)
{
	int i;

	if (!dst || !src || size < 1)
		return ;
	i = 0;
	while (i < size)
	{
		dst[i] = str_dup(src[i]);
		i++;
	}
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


//Example usage: string_findall
/*
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
