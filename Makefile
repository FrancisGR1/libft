CC = cc
CFLAGS = -Wall -Werror -Wextra
SOURCES = *.c
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
TARGET = libft.a

# Target Build
all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
