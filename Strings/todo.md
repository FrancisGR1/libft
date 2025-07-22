grep -R -n -A2 "@TODO\|TODO" Strings/

eliminar quase todos as @TODO quando fizer as funcs abaixo

formatar Strings/ para aplicar norminette

Classic Strings:
- strcasecmp
- strncpy
- strtok
- strspn
- strcspn
- islower
- isupper
->snprintf?

não vale a pena implementar:
- atof
- strod
eliminar conversões em Strings/ ?

./str_from_primitives.c:7:	//@TODO: implementar ft_snprintf
./str_from_primitives.c-8-	snprintf(buffer, sizeof(buffer), "%d", value);
./str_from_primitives.c-9-	converted = str_create(buffer);
--
./str_from_primitives.c:17:	//@TODO: implementar ft_snprintf
./str_from_primitives.c-18-	snprintf(buffer, sizeof(buffer), "%f", value);
./str_from_primitives.c-19-	converted = str_create(buffer);
--
./str_from_primitives.c:27:	//@TODO: implementar ft_snprintf
./str_from_primitives.c-28-	snprintf(buffer, sizeof(buffer), "%f", value);
./str_from_primitives.c-29-	converted = str_create(buffer);
--
./str_split.c:3://@TODO: implementar strtok
./str_split.c-4-static size_t count_splits_for_char_delim(const t_string *str, const char *delimiter)
./str_split.c-5-{
--
./str_split.c:28://@TODO: implementar strtok
./str_split.c-29-t_string **str_split_using_char_as_delim(const t_string* str, const char* delimiters, int* count)
./str_split.c-30-{
--
./str_split.c:56://@TODO: null checks - can't because of norminette rn
./str_split.c-57-static size_t count_splits_for_str_delim(const t_string *str, const char *delimiter)
./str_split.c-58-{
--
./str_split.c:83://@TODO: should cleanup if str_create() goes bad, but norminette, lol.... so cba!
./str_split.c:84://@TODO: should also null check temp, params; size check num_splits, meh
./str_split.c-85-static bool insert_split_substrs(const t_string *original_str, t_string **array_to_insert, const char *delimiter, size_t num_splits)
./str_split.c-86-{
--
./str_to_primitives.c:18:	//@TODO: implementar atof()
./str_to_primitives.c-19-	return (atof(str->data));
./str_to_primitives.c-20-}
--
./str_to_primitives.c:26:	//@TODO: implementar str_empty()
./str_to_primitives.c-27-	if (str_empty(str))
./str_to_primitives.c-28-		return (0);
./str_to_primitives.c:29:	//@TODO: implementar strtod()
./str_to_primitives.c-30-	return (strtod(str->data, NULL));
./str_to_primitives.c-31-}
--
./str_substr.c:20:	//@TODO: implementar strncpy()
./str_substr.c-21-	strncpy(substr->data, str->data + pos, len);
./str_substr.c-22-	substr->data[len] = '\0';
--
./strings.h:10://@TODO: alterar nome com "STRING" como prefixo
./strings.h-11-#define MAX_STRING_SIZE (SIZE_MAX / 2)
./strings.h-12-
./str_compare.c:28:	//@TODO: implementar strcasecmp()
./str_compare.c-29-	return (strcasecmp(str1->data, str2->data));
./str_compare.c-30-}
--
./str_from_primitives.c:7:	//@TODO: implementar ft_snprintf
./str_from_primitives.c-8-	snprintf(buffer, sizeof(buffer), "%d", value);
./str_from_primitives.c-9-	converted = str_create(buffer);
--
./str_from_primitives.c:17:	//@TODO: implementar ft_snprintf
./str_from_primitives.c-18-	snprintf(buffer, sizeof(buffer), "%f", value);
./str_from_primitives.c-19-	converted = str_create(buffer);
--
./str_from_primitives.c:27:	//@TODO: implementar ft_snprintf
./str_from_primitives.c-28-	snprintf(buffer, sizeof(buffer), "%f", value);
./str_from_primitives.c-29-	converted = str_create(buffer);
--
./str_split.c:3://@TODO: implementar strtok
./str_split.c-4-static size_t count_splits_for_char_delim(const t_string *str, const char *delimiter)
./str_split.c-5-{
--
./str_split.c:28://@TODO: implementar strtok
./str_split.c-29-t_string **str_split_using_char_as_delim(const t_string* str, const char* delimiters, int* count)
./str_split.c-30-{
--
./str_split.c:56://@TODO: null checks - can't because of norminette rn
./str_split.c-57-static size_t count_splits_for_str_delim(const t_string *str, const char *delimiter)
./str_split.c-58-{
--
./str_split.c:83://@TODO: should cleanup if str_create() goes bad, but norminette, lol.... so cba!
./str_split.c:84://@TODO: should also null check temp, params; size check num_splits, meh
./str_split.c-85-static bool insert_split_substrs(const t_string *original_str, t_string **array_to_insert, const char *delimiter, size_t num_splits)
./str_split.c-86-{
--
./str_to_primitives.c:18:	//@TODO: implementar atof()
./str_to_primitives.c-19-	return (atof(str->data));
./str_to_primitives.c-20-}
--
./str_to_primitives.c:26:	//@TODO: implementar str_empty()
./str_to_primitives.c-27-	if (str_empty(str))
./str_to_primitives.c-28-		return (0);
./str_to_primitives.c:29:	//@TODO: implementar strtod()
./str_to_primitives.c-30-	return (strtod(str->data, NULL));
./str_to_primitives.c-31-}
--
./str_substr.c:20:	//@TODO: implementar strncpy()
./str_substr.c-21-	strncpy(substr->data, str->data + pos, len);
./str_substr.c-22-	substr->data[len] = '\0';
--
./strings.h:10://@TODO: alterar nome com "STRING" como prefixo
./strings.h-11-#define MAX_STRING_SIZE (SIZE_MAX / 2)
./strings.h-12-
