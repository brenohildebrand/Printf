# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 15:30:27 by bhildebr          #+#    #+#              #
#    Updated: 2023/09/14 23:29:17 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := gcc
CFLAGS := -MMD -MP

SOURCES = ./libft/*.c ./printf/*.c ./buffer/*.c
OBJECTS = ./*.o
DEPENDS = ./*.d

all: $(NAME) 

bonus: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) -c
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	rm -f $(DEPENDS)

fclean: clean
	rm -f $(NAME)
	@rm -f ./test

re: fclean all

test: $(NAME) 
	@$(CC) $(CFLAGS) ./tests/printf.test.c -o test -L. -l:libftprintf.a
	@./test

.PHONY: all clean fclean re test
