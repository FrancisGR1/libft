CC = cc
CFLAGS = -Wall -Werror -Wextra
SOURCES = *.c
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
