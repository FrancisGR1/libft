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

HEADER = libft.h

#AFAZER: organizar ficheiros em pastas
SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_isspace.c array_len.c \
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
	ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_strndup.c ft_substr.c ft_strjoin.c ft_strjoin_until.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_atoi_base.c ft_atoi_long.c \
	ft_getc.c ft_putns.c ft_puts.c print_bits.c get_next_line.c ft_digit_count.c \
	ft_fprintf.c  ft_fprintf_utils/ft_printmemory.c ft_fprintf_utils/ft_putnbru_fd.c \
	ft_fprintf_utils/ft_tohexa.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	arena.c ft_realloc.c freen.c dynamic_array.c strings.c queues.c \
	debuggers.c \

OBJECTS = $(SOURCES:.c=.o)

# Target Build
all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	ar rcs $@ $(OBJECTS)
	ranlib $@
clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

watch:
	@while inotifywait -r -e modify,delete,move .; do \
		$(MAKE); \
		done
.PHONY: all bonus clean fclean re watch
