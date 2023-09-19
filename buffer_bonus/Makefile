# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 12:45:43 by bhildebr          #+#    #+#              #
#    Updated: 2023/09/19 17:18:42 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libbuffer.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = \
	add_buffer_to_buffer_bonus.c \
	add_character_to_buffer_bonus.c \
	add_cstring_to_buffer_bonus.c \
	add_unsigned_character_to_buffer_bonus.c \
	append_character_to_buffer_bonus.c \
	append_cstring_to_buffer_bonus.c \
	free_buffer_bonus.c \
	malloc_buffer_bonus.c \
	prepend_character_to_buffer_bonus.c \
	print_buffer_bonus.c \
	realloc_buffer_content_bonus.c

HEADERS = \
	buffer_bonus.h

OBJECTS = \
	add_buffer_to_buffer_bonus.o \
	add_character_to_buffer_bonus.o \
	add_cstring_to_buffer_bonus.o \
	add_unsigned_character_to_buffer_bonus.o \
	append_character_to_buffer_bonus.o \
	append_cstring_to_buffer_bonus.o \
	free_buffer_bonus.o \
	malloc_buffer_bonus.o \
	prepend_character_to_buffer_bonus.o \
	print_buffer_bonus.o \
	realloc_buffer_content_bonus.o

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADERS)
	ar rcs $(NAME) $(OBJECTS)
	
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
