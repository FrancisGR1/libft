/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:18:51 by frmiguel          #+#    #+#             */
/*   Updated: 2024/11/10 21:18:51 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

t_arena	*arena_init(size_t size)
{
	t_arena	*region;

	region = malloc(sizeof(*region));
	region->memory = malloc(size);
	ft_memset(region->memory, 0, size);
	region->current_size = 0;
	region->limit = size;
	region->end = region->memory + region->limit;
	region->next = NULL;
	return (region);
}

void	*arena_alloc(t_arena **region, size_t nbytes, size_t size)
{
	const size_t	size_bytes = size * nbytes;
	void			*result;
	t_arena			*head;

	if (size_bytes > (*region)->limit - (*region)->current_size)
	{
		head = *region;
		while ((*region)->next)
			*region = (*region)->next;
		(*region)->next = arena_init(size_bytes);
		(*region)->next->current_size = size_bytes;
		result = (char *)(*region)->next->memory;
		*region = head;
	}
	else
	{
		result = (char *)(*region)->memory + (*region)->current_size;
		(*region)->current_size += size_bytes;
	}
	return (result);
}

void	arena_destroy(t_arena *arena)
{
	t_arena	*tmp;

	while (arena != NULL)
	{
		tmp = arena->next;
		free(arena->memory);
		free(arena);
		arena = tmp;
	}
}

// visualização da memória: bytes ocupados: "|", nulos: "."
/*
void	arena_visualizer(t_arena *region)
{
	size_t			bytes_used;
	size_t			bytes_total;
	t_arena			*ptr;
	unsigned char	*start;
	unsigned char	*end;

   bytes_used = 0;
   bytes_total = 0;
   ptr = region;
   while (ptr)
   {
		start = (unsigned char*) ptr->memory;
		end = (unsigned char*) ptr->end;
		while (start < end)
		{
			if (*start)
			{
				ft_fprintf(STDOUT, "|");
				bytes_used++;
			}
			else
			{
				ft_fprintf(STDOUT, ".");
			}
			start++;
		}
		bytes_total += ptr->limit;
		if (ptr->next)
			ft_fprintf(STDOUT, "\n\n>--->\n\n");
		ptr = ptr->next;
   }
   ft_fprintf(STDOUT, "\n%ld out of %ld\n", bytes_used, bytes_total);
}
*/

// EXAMPLE
/*
void	print_nums(int *i, int *end)
{
	while (i < end)
	{
		printf("%d\n", *i);
		i++;
	}
}

int main (int argc, char *argv[])
{
	t_arena	*region;
	char	*string;
	t_arena	*ptr;

	if (argc < 2)
		return (printf("./main <arg>\n"));
	region = arena_init(SIZE);
	string = (char *)arena_alloc(&region, sizeof(char) , strlen(argv[1]) + 1);
	strncpy(string, argv[1], strlen(argv[1]));
	printf("%s\n", string);
	arena_visualizer(region);
	printf("\n\n\n");
	ptr = region;
	while (ptr){
		printf("node\n");
		ptr = ptr->next;
	}
	printf("destroying\n");
	arena_destroy(region);
}
*/
// Criar um bloco de memória pré-alocado
// Incluir uma série de dados
// Libertar tudo de uma vez
