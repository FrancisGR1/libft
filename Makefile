# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmiguel <frmiguel@student.42Lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 19:51:14 by frmiguel          #+#    #+#              #
#    Updated: 2023/10/14 20:55:14 by frmiguel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
DEBUG = -g #-DDEBUG_REPLACE=1
CFLAGS = -Wall -Werror -Wextra $(DEBUG)

MK = Makefile

HEADER = libft.h 

#memory 
MEMORY_DIR = Memory
MEMORY_SRC = \
	     freen.c \
	     ft_bzero.c \
	     ft_calloc.c \
	     ft_memcat.c \
	     ft_memchr.c \
	     ft_memcmp.c \
	     ft_memcpy.c \
	     ft_memmove.c \
	     ft_memset.c \
	     ft_realloc.c \
	     swap_bytes.c \
	     cmp_ptrs.c \
	     debuggers.c
HEADER += $(MEMORY_DIR)/memory.h
SOURCES = $(addprefix $(MEMORY_DIR)/, $(MEMORY_SRC))


#strings inspired by std::string
STR_DIR = Strings
STR_SRC = \
	  string_creation.c \
	  string_destruction.c \
	  string_internals.c \
	  str_from_primitives.c \
	  str_to_primitives.c \
	  str_insert.c \
	  str_copy.c \
	  str_replace.c \
	  str_size.c \
	  str_modify_size.c \
	  str_split.c \
	  str_substr.c \
	  str_join.c \
	  str_search.c \
	  str_search_not_of.c \
	  str_compare.c \
	  str_match.c \
	  str_arithmetics.c \
	  str_is.c \
	  str_is_p2.c \
	  str_remove.c \
	  str_trim.c \
	  str_case.c \
	  str_accessors.c
HEADER += $(STR_DIR)/strings.h $(STR_DIR)/string_internals.h
SOURCES += $(addprefix $(STR_DIR)/, $(STR_SRC))

#checkers
CHECKERS_DIR = Checkers
CHECKERS_SRC = ft_isalnum.c\
	       ft_isalpha.c \
	       ft_isascii.c \
	       ft_isdigit.c \
	       ft_isprint.c \
	       ft_ispunctuation.c \
	       ft_isspace.c \
	       ft_isvowel.c
HEADER += $(CHECKERS_DIR)/checkers.h
SOURCES += $(addprefix $(CHECKERS_DIR)/, $(CHECKERS_SRC))

#classic strings
CSTR_DIR = Classic_Strings
CSTR_SRC = \
	   ft_atoi_long.c \
	   ft_atoi.c \
	   ft_atoi_base.c \
	   ft_itoa.c \
	   ft_len_until.c \
	   ft_split.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strjoin_until.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strncpy.c \
	   ft_strcpy.c \
	   ft_strlen.c \
	   ft_strmapi.c \
	   ft_strncmp.c \
	   ft_strcasecmp.c \
	   ft_strcmp.c \
	   ft_strndup.c \
	   ft_strnstr.c \
	   ft_strstr.c \
	   ft_strrchr.c \
	   ft_strtrim.c \
	   ft_substr.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   rand_string.c \
	   ft_strspn.c \
	   ft_strcspn.c \
	   ft_strtok.c \
	   ft_islower.c \
	   ft_isupper.c

HEADER += $(CSTR_DIR)/classic_strings.h
SOURCES += $(addprefix $(CSTR_DIR)/, $(CSTR_SRC))

#math utils
MATH_DIR = Math
MATH_SRC = \
	   ft_digit_count.c \
	   ft_rand.c
HEADER += $(MATH_DIR)/math.h
SOURCES += $(addprefix $(MATH_DIR)/, $(MATH_SRC))


#functions for printing, error logging, etc
WRITE_DIR = Write
WRITE_SRC = \
	    ft_fprintf.c \
	    ft_putchar_fd.c \
	    ft_putendl_fd.c \
	    ft_putnbr_fd.c \
	    ft_putnbru_fd.c \
	    ft_putns.c \
	    ft_puts.c \
	    ft_putstr_fd.c \
	    ft_snprintf.c \
	    print_bits.c
PRINTF_AUX_SRC = \
		 ft_fprintf_utils/ft_printmemory.c \
		 ft_fprintf_utils/ft_tohexa.c
HEADER += $(WRITE_DIR)/write.h
SOURCES += $(addprefix $(WRITE_DIR)/, $(WRITE_SRC))
SOURCES += $(addprefix $(WRITE_DIR)/, $(PRINTF_AUX_SRC))

#files
FILES_DIR = Files
FILES_SRC = \
	    ft_getc.c \
	    get_next_line.c \
	    get_next_line_to_str.c
HEADER += $(FILES_DIR)/files.h
SOURCES += $(addprefix $(FILES_DIR)/, $(FILES_SRC))

#custom allocator
ARENA_DIR = Arena
ARENA_SRC = \
	    arena.c \
	    arena_watermark.c \
	    arena_internals.c \
	    arena_internals_reset_chunks.c
HEADER += $(ARENA_DIR)/arena.h
SOURCES += $(addprefix $(ARENA_DIR)/, $(ARENA_SRC))

#------------
DS_DIR = Data_Structures

#arrays
ARR_DIR = $(DS_DIR)/Arrays
ARR_SRC = \
	  array_len.c \
	  free_arr.c
HEADER += $(ARR_DIR)/array.h
SOURCES += $(addprefix $(ARR_DIR)/, $(ARR_SRC))

#dynamic arrays
DARR_DIR = $(DS_DIR)/Dynamic_Arrays
DARR_SRC = \
	   dynamic_array.c \
	   darr_free.c
HEADER += $(DARR_DIR)/dynamic_array.h
SOURCES += $(addprefix $(DARR_DIR)/, $(DARR_SRC))

#lists
LST_DIR = $(DS_DIR)/Lists
LST_SRC = ft_lstadd_back.c \
	  ft_lstadd_front.c \
	  ft_lstclear.c \
	  ft_lstdelone.c \
	  ft_lstrem_node.c \
	  ft_lstiter.c \
	  ft_lstlast.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_lstsize.c
HEADER += $(LST_DIR)/lists.h
SOURCES += $(addprefix $(LST_DIR)/, $(LST_SRC))

#queues
Q_DIR = $(DS_DIR)/Queues
Q_SRC = \
	queues.c \
	queue_utils.c
HEADER += $(Q_DIR)/queues.h
SOURCES += $(addprefix $(Q_DIR)/, $(Q_SRC))

#hash table
HT_DIR = $(DS_DIR)/Hash_Table
HT_SRC = \
	 hash.c \
	 hash_table.c
HEADER += $(HT_DIR)/hash_table.h
SOURCES += $(addprefix $(HT_DIR)/, $(HT_SRC))

OBJ_DIR = obj
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

# Target Build
all: $(NAME) $(HEADER) $(MK)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) 

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: watch
watch:
	@while inotifywait -r -e modify,delete,move .; do \
		$(MAKE); \
		done
