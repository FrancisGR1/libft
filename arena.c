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

//arena_free_chunk()
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
	region->start_ptrs = darr_init(sizeof (void *));
//	region->free_chunks = darr_init(sizeof (void*) * FREE_CHUNKS);
	return (region);
}

//TODO: temporário, mudar de sítio
int cmp_nums(void *el1, void *el2)
{
	return ((long long *)el1 - (long long *)el2);
}

static void _arena_save_ptr(t_dynamic_array *start_ptrs, void *ptr)
{
	darr_append(start_ptrs, &ptr);
	darr_sort(start_ptrs, cmp_nums);
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
		_arena_save_ptr((*region)->next->start_ptrs, result);
		*region = head;
	}
	else
	{
		result = (char *)(*region)->memory + (*region)->current_size;
		_arena_save_ptr((*region)->start_ptrs, result);
		(*region)->current_size += size_bytes;
	}
	return (result);
}

static t_arena *_arena_of_ptr(t_arena *arena_list, void *ptr)
{
	t_arena *arena_of_ptr;

	if (!arena_list || !ptr)
		return (NULL);
	arena_of_ptr = arena_list;
	while (arena_of_ptr && (ptr < arena_of_ptr->memory || ptr > arena_of_ptr->end))
		arena_of_ptr = arena_of_ptr->next;
	return (arena_of_ptr);
}

static void *_arena_lookup_next_ptr(t_arena *arena, void *curr_ptr)
{
	size_t i;
	t_dynamic_array *start_ptrs;
	void **ptrs_array;

	i = 0;
	start_ptrs = arena->start_ptrs;
	ptrs_array = start_ptrs->data;
	while (i < start_ptrs->len)
	{
		if (curr_ptr < ptrs_array[i])
			return (ptrs_array[i]);
		i++;
	}
	return (arena->end);
}

void arena_reset(t_arena *arena_list, void *ptr)
{
	size_t bytes_to_reset;
	void *next_ptr;
	t_arena *arena;

	if (!arena_list || !ptr)
		return ;
	arena = _arena_of_ptr(arena_list, ptr);
	if (!arena)
		return ;
	next_ptr = _arena_lookup_next_ptr(arena, ptr);
	if (!next_ptr)
		return ;
	bytes_to_reset = next_ptr - ptr;
	ft_memset(ptr, 0, bytes_to_reset);
	//TODO:
	//remover ptr de start_ptrs
	//TODO:
	//_arena_save_free_chunk(arena, ptr, bytes_to_reset);
}

void	arena_destroy(t_arena *arena)
{
	t_arena	*tmp;

	while (arena != NULL)
	{
		tmp = arena->next;
		freen((void *)&arena->memory);
		darr_free(arena->start_ptrs);
		//darr_free(arena->free_chunks);
		freen((void *)&arena);
		arena = tmp;
	}
}

// visualização da memória: bytes ocupados: "|", nulos: "."
void	arena_visualizer(char *msg, t_arena *region)
{
	size_t			bytes_used;
	size_t			bytes_total;
	t_arena			*ptr;
	unsigned char	*start;
	unsigned char	*end;

	if (!region)
	{
		ft_fprintf(STDOUT, "NULL REGION\n");
		return ;
	}
   bytes_used = 0;
   bytes_total = 0;
   ptr = region;
   ft_fprintf(STDOUT, "======== %s ========\n", msg);
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
	char	*string1;
	char	*string2;
	char	*string3;
	char	*string4;
	char	*string5;
	t_arena	*ptr;

	if (argc < 2)
		return (printf("./main <arg>\n"));
	region = arena_init(ALLOC_SIZE);
	string = (char *)arena_alloc(&region, sizeof(char) , strlen(argv[1]) + 1);
	strncpy(string, argv[1], strlen(argv[1]));
	string1 = (char *)arena_alloc(&region, sizeof(char) , strlen(argv[1]) + 1);
	strncpy(string1, argv[1], strlen(argv[1]));
	string2 = (char *)arena_alloc(&region, sizeof(char) , strlen(argv[1]) + 1);
	strncpy(string2, argv[1], strlen(argv[1]));
	string3 = (char *)arena_alloc(&region, sizeof(char) , strlen(argv[1]) + 1);
	strncpy(string3, argv[1], strlen(argv[1]));
	string4 = (char *)arena_alloc(&region, sizeof(char) , strlen(argv[1]) + 1);
	strncpy(string4, argv[1], strlen(argv[1]));
	string5 = (char *)arena_alloc(&region, sizeof(char) , strlen(argv[1]) + 1);
	strncpy(string5, argv[1], strlen(argv[1]));
	printf("%s\n", string);
	arena_visualizer("BEFORE", region);
	arena_reset(region, string);
	arena_visualizer("AFTER", region);
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
// Libertar tudo de s uma vez
