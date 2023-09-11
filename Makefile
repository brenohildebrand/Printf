# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 15:30:27 by bhildebr          #+#    #+#              #
#    Updated: 2023/09/11 16:24:55 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# IMPORTANT
#	change makefile to compile the Libft first and then use its libft.a output
#	to compile the printf lib.

NAME     := printf.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
CTESTFLAGS := -MMD -MP

INCLUDES = ./includes/

SOURCES = ./source/buffer.c ./source/printf.c
OBJECTS = ./buffer.o ./printf.o
DEPENDS = ./buffer.d ./printf.d

TEST = ./tests/test00.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) -c
	ar rcs $(NAME) $(OBJECTS)

test: $(NAME)
	gcc $(TEST) -o test -L. -l:printf.a

run: test
	@./test

clean:
	rm -f $(OBJECTS) $(DEPENDS)

fclean: clean
	rm -f $(NAME)
	rm -f $(TESTNAME)
	
re: fclean all

.PHONY: all clean fclean re
