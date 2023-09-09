# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 15:30:27 by bhildebr          #+#    #+#              #
#    Updated: 2023/09/09 14:11:35 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     := printf.a
TESTNAME := test

CC := gcc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
CTESTFLAGS := -MMD -MP

INCLUDES = ./includes/printf.h

SOURCES = ./source/printf.c
OBJECTS = ./printf.o
DEPENDS = ./printf.d
TESTS   = ./tests/main.c

all: $(NAME)

run: test
	@./test

test:
	$(CC) $(CTESTFLAGS) $(SOURCES) -c -I$(INCLUDES)
	ar rcs $(NAME) $(OBJECTS)
	gcc $(TESTS) -o $(TESTNAME) -L . -l:printf.a

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) -c -I$(INCLUDES)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(DEPENDS)

fclean: clean
	rm -f $(NAME)
	rm -f $(TESTNAME)
	
re: fclean all

.PHONY: all clean fclean re
