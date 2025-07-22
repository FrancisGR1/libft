/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:18:51 by frmiguel          #+#    #+#             */
/*   Updated: 2025/07/22 17:02:11 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "arena_internals.h"

t_arena	*arena_init(size_t region_size)
{
	t_arena	*region;

	region = malloc(sizeof(*region));
	region->memory = malloc(region_size);
	ft_memset(region->memory, 0, region_size);
	region->current_size = 0;
	region->limit = region_size;
	region->end = region->memory + region->limit;
	region->next = NULL;
	region->watermark = NULL;
	region->data_ptrs = darr_init(sizeof(void *) * START_PTRS, DA_DEFAULT_SIZE);
	region->reset_chunks = darr_init(sizeof(void *) * RESET_CHUNKS,
			DA_DEFAULT_SIZE);
	return (region);
}

void	*arena_alloc(t_arena **region, size_t nbytes, size_t size)
{
	const size_t	size_bytes = size * nbytes;
	const void		*reset_chunk = _arena_use_reset_chunk(*region, size_bytes);
	void			*result;
	t_arena			*head;

	if (reset_chunk)
		return ((void *)reset_chunk);
	if (size_bytes > (*region)->limit - (*region)->current_size)
	{
		head = *region;
		while ((*region)->next)
			*region = (*region)->next;
		(*region)->next = arena_init(size_bytes);
		(*region)->next->current_size = size_bytes;
		result = (char *)(*region)->next->memory;
		_arena_save_ptr((*region)->next->data_ptrs, result);
		*region = head;
	}
	else
	{
		result = (char *)(*region)->memory + (*region)->current_size;
		_arena_save_ptr((*region)->data_ptrs, result);
		(*region)->current_size += size_bytes;
	}
	return (result);
}

void	arena_reset(t_arena *arena_list, void *ptr)
{
	size_t	bytes_to_reset;
	void	*next_ptr;
	t_arena	*arena;

	if (!arena_list || !ptr)
		return ;
	arena = _arena_of_ptr(arena_list, ptr);
	if (!arena)
		return ;
	next_ptr = _arena_lookup_next_ptr(arena, ptr);
	if (!next_ptr)
		return ;
	bytes_to_reset = next_ptr - ptr;
	darr_remove(arena->data_ptrs, ptr);
	ft_memset(ptr, 0, bytes_to_reset);
	_arena_save_ptr(arena->reset_chunks, ptr);
}

void	arena_destroy(t_arena *arena)
{
	t_arena	*tmp;

	while (arena != NULL)
	{
		tmp = arena->next;
		freen((void *)&arena->memory);
		darr_free(arena->data_ptrs);
		darr_free(arena->reset_chunks);
		freen((void *)&arena);
		arena = tmp;
	}
}

// visualização da memória:
// bytes ocupados: "|",
// bytes nulos   : "."
/*
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
				if (ft_isascii(*start))
					ft_fprintf(STDOUT, "%c", *start);
				else
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
	ft_fprintf(STDOUT, "\n%d out of %d\n", bytes_used, bytes_total);
}
*/

// Example usage
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
   arena_set_watermark(region);
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
   arena_reset(region, string4);
   arena_visualizer("AFTER", region);
   string = (char *)arena_alloc(&region, sizeof(char) , strlen(argv[1]) + 1);
   strncpy(string, argv[1], strlen(argv[1]));
   string4 = (char *)arena_alloc(&region, sizeof(char) , strlen(argv[1]) + 1);
   strncpy(string4, argv[1], strlen(argv[1]));
   arena_visualizer("AFTER CHUNK", region);
   printf("in reset chunk: %s\n", string);
   printf("in reset chunk 2: %s\n", string4);
   printf("\n\n\n");
   ptr = region;
   while (ptr){
   printf("node\n");
   ptr = ptr->next;
   }
   printf("destroying\n");
   arena_reset_to_watermark(region);
   arena_visualizer("AFTER WATERMARK", region);
   arena_destroy(region);
   }
   */
