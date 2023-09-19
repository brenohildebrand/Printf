# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 12:45:43 by bhildebr          #+#    #+#              #
#    Updated: 2023/09/19 15:51:57 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libbuffer.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = \
	add_buffer_to_buffer.c \
	add_character_to_buffer.c \
	add_cstring_to_buffer.c \
	add_unsigned_character_to_buffer.c \
	append_character_to_buffer.c \
	append_cstring_to_buffer.c \
	free_buffer.c \
	malloc_buffer.c \
	prepend_character_to_buffer.c \
	print_buffer.c \
	realloc_buffer_content.c

HEADERS = \
	buffer.h

OBJECTS = \
	add_buffer_to_buffer.o \
	add_character_to_buffer.o \
	add_cstring_to_buffer.o \
	add_unsigned_character_to_buffer.o \
	append_character_to_buffer.o \
	append_cstring_to_buffer.o \
	free_buffer.o \
	malloc_buffer.o \
	prepend_character_to_buffer.o \
	print_buffer.o \
	realloc_buffer_content.o

DEPENDS = \
	add_buffer_to_buffer.d \
	add_character_to_buffer.d \
	add_cstring_to_buffer.d \
	add_unsigned_character_to_buffer.d \
	append_character_to_buffer.d \
	append_cstring_to_buffer.d \
	free_buffer.d \
	malloc_buffer.d \
	prepend_character_to_buffer.d \
	print_buffer.d \
	realloc_buffer_content.d

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADERS)
	ar rcs $(NAME) $(OBJECTS)
	
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re