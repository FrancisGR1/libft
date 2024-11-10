/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:19:04 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:46:18 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string	new_str(char *s, t_str_type type)
{
	t_string	str;

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

bool	str_is_null(t_string str)
{
	return (!str.s || str.type == STR_NULL);
}

t_string	cstr_to_str_ptr(char *raw_str, int size)
{
	t_string	str;

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

t_string	cstr_to_str(char *raw_str)
{
	t_string	str;

	if (!raw_str)
		return (new_str(NULL, 0));
	str.len = ft_strlen(raw_str);
	str.s = (char *)malloc(str.len + 1);
	str.type = STR_ALLOCATED;
	if (str.len > 0)
		str.end = str.s + str.len - 1;
	else
		str.end = str.s;
	if (ft_strlcpy(str.s, raw_str, str.len + 1) == 0)
		str.s[0] = '\0';
	return (str);
}

t_string	cstr_to_str_nsize(char *raw_str, int size)
{
	t_string	str;

	if (!raw_str || size < 0)
		return (new_str(NULL, 0));
	str.len = size;
	str.s = (char *)malloc(str.len + 1);
	str.type = STR_ALLOCATED;
	if (str.len > 0)
		str.end = str.s + str.len - 1;
	else
		str.end = str.s;
	if (ft_strlcpy(str.s, raw_str, str.len + 1) == 0)
		str.s[0] = '\0';
	return (str);
}

// Example usage: string_split
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

// Example usage: string_findall
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
