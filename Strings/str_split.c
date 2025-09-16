/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:50:05 by frmiguel          #+#    #+#             */
/*   Updated: 2025/09/16 09:32:28 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

static size_t	count_splits_for_char_delim(const t_string *str,
					const char *delimiter);
static bool		insert_split_substrs(const t_string *original_str,
					t_string **array_to_insert, const char *delimiter,
					size_t num_splits);
static size_t	count_splits_for_str_delim(const t_string *str,
					const char *delimiter);

t_string	**str_split_using_str_as_delim(const t_string *str,
		const char *delimiter, int *count)
{
	size_t		num_splits;
	t_string	**splits;

	if (str == NULL || delimiter == NULL || count == NULL)
		return (NULL);
	num_splits = count_splits_for_str_delim(str, delimiter);
	if (num_splits == 0)
		return (NULL);
	splits = malloc(sizeof(t_string *) * num_splits);
	if (splits == NULL)
		return (NULL);
	if (insert_split_substrs(str, splits, delimiter, num_splits) == true)
	{
		*count = (int)num_splits;
		return (splits);
	}
	else
	{
		free(splits);
		return (NULL);
	}
}

t_string	**str_split_using_char_as_delim(const t_string *str,
		const char *delimiters, int *count)
{
	size_t		num_splits;
	char		*temp;
	char		*token;
	size_t		i;
	t_string	**splits;

	num_splits = count_splits_for_char_delim(str, delimiters);
	if (num_splits == 0 || count == NULL)
		return (NULL);
	splits = malloc(sizeof(t_string *) * num_splits);
	if (splits == NULL)
		return (NULL);
	temp = ft_strdup(str->data);
	token = strtok(temp, delimiters);
	i = 0;
	while (token != NULL && i < num_splits)
	{
		splits[i] = str_create(token);
		i++;
		token = strtok(NULL, delimiters);
	}
	free(temp);
	*count = (int)num_splits;
	return (splits);
}

static size_t	count_splits_for_char_delim(const t_string *str,
		const char *delimiter)
{
	size_t	num_splits;
	char	*temp;
	char	*token;

	if (str == NULL || delimiter == NULL || str->data == NULL)
		return (0);
	temp = ft_strdup(str->data);
	if (temp == NULL)
		return (0);
	token = strtok(temp, delimiter);
	if (token == NULL)
		return (0);
	num_splits = 0;
	while (token != NULL)
	{
		num_splits++;
		token = strtok(NULL, delimiter);
	}
	free(temp);
	return (num_splits);
}

//@TODO: null checks - can't because of norminette rn
static size_t	count_splits_for_str_delim(const t_string *str,
		const char *delimiter)
{
	char			*temp;
	char			*current;
	char			*found;
	const size_t	delim_len = ft_strlen(delimiter);
	size_t			num_splits;

	if (str == NULL || delimiter == NULL || str->data == NULL || delim_len == 0)
		return (0);
	temp = ft_strdup(str->data);
	num_splits = 0;
	current = temp;
	found = ft_strstr(current, delimiter);
	while (found != NULL)
	{
		num_splits++;
		current = found + delim_len;
		found = ft_strstr(current, delimiter);
	}
	if (num_splits > 0 || ft_strlen(temp) > 0)
		num_splits++;
	free(temp);
	return (num_splits);
}

//@TODO: should cleanup if str_create() goes bad,
// but norminette, lol.... so cba!
//@TODO: should also null check temp, params; size check num_splits, meh
static bool	insert_split_substrs(const t_string *original_str,
		t_string **array_to_insert, const char *delimiter, size_t num_splits)
{
	char			*temp;
	char			*current;
	char			*found;
	const size_t	delim_len = ft_strlen(delimiter);
	int				i;

	temp = ft_strdup(original_str->data);
	current = temp;
	i = -1;
	while (++i < (int)num_splits)
	{
		found = ft_strstr(current, delimiter);
		if (found)
		{
			*found = '\0';
			array_to_insert[i] = str_create(current);
			current = found + delim_len;
		}
		else
			array_to_insert[i] = str_create(current);
	}
	free(temp);
	return (true);
}
