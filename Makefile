# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 15:30:27 by bhildebr          #+#    #+#              #
#    Updated: 2023/09/19 16:10:33 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

BUFFERDIR = buffer
LIBFTDIR = libft
PRINTFDIR = printf

LIBBUFFER = $(BUFFERDIR)/libbuffer.a
LIBFT = $(LIBFTDIR)/libft.a
LIBPRINTF = $(PRINTFDIR)/libprintf.a

OBJECTS = \
	buffer/add_buffer_to_buffer.o \
	buffer/add_character_to_buffer.o \
	buffer/add_cstring_to_buffer.o \
	buffer/add_unsigned_character_to_buffer.o \
	buffer/append_character_to_buffer.o \
	buffer/append_cstring_to_buffer.o \
	buffer/free_buffer.o \
	buffer/malloc_buffer.o \
	buffer/prepend_character_to_buffer.o \
	buffer/print_buffer.o \
	buffer/realloc_buffer_content.o \
	\
	libft/ft_atoi.o \
	libft/ft_bzero.o \
	libft/ft_calloc.o \
	libft/ft_int_itoa_base.o \
	libft/ft_isalnum.o \
	libft/ft_isalpha.o \
	libft/ft_isascii.o \
	libft/ft_isdigit.o \
	libft/ft_isprint.o \
	libft/ft_itoa.o \
	libft/ft_long_long_int_itoa_base.o \
	libft/ft_memchr.o \
	libft/ft_memcmp.o \
	libft/ft_memcpy.o \
	libft/ft_memmove.o \
	libft/ft_memset.o \
	libft/ft_putchar_fd.o \
	libft/ft_putendl_fd.o \
	libft/ft_putnbr_fd.o \
	libft/ft_putstr_fd.o \
	libft/ft_split.o \
	libft/ft_strchr.o \
	libft/ft_strdup.o \
	libft/ft_striteri.o \
	libft/ft_strjoin.o \
	libft/ft_strlcat.o \
	libft/ft_strlcpy.o \
	libft/ft_strlen.o \
	libft/ft_strmapi.o \
	libft/ft_strncmp.o \
	libft/ft_strnstr.o \
	libft/ft_strchr.o \
	libft/ft_strtrim.o \
	libft/ft_substr.o \
	libft/ft_tolower.o \
	libft/ft_toupper.o \
	libft/ft_unsigned_int_itoa_base.o \
	libft/ft_unsigned_long_long_int_itoa_base.o \
	\
	printf/add_conversion_specification_to_buffer.o \
	printf/convert_c.o \
	printf/convert_d.o \
	printf/convert_i.o \
	printf/convert_p.o \
	printf/convert_percentage.o \
	printf/convert_s.o \
	printf/convert_u.o \
	printf/convert_upper_x.o \
	printf/convert_x.o \
	printf/parse_conversion_specification.o \
	printf/parse_conversion_specifier.o \
	printf/parse_flags.o \
	printf/parse_formatted_string.o \
	printf/parse_minimum_field_width.o \
	printf/parse_precision.o \
	printf/printf.o \
	printf/process_alternate_form.o \
	printf/process_conversion_specifier.o \
	printf/process_signal.o \
	printf/process_spaces.o \
	printf/process_specs.o \
	printf/process_zeros.o

all: norm libs $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

norm:
	@printf '[NORM]\n'
	@norminette
	@printf '\n'

libs: buffer libft printf

buffer:
	@printf '[BUFFER]\n'
	$(MAKE) all -C $(BUFFERDIR)

libft:
	@printf '\n[LIBFT]\n'
	$(MAKE) all -C $(LIBFTDIR)
	
printf:
	@printf '\n[PRINTF]\n'
	$(MAKE) all -C $(PRINTFDIR)
	@printf '\n'

clean:
	@printf '[BUFFER]\n'
	$(MAKE) clean -C $(BUFFERDIR)
	@printf '\n[LIBFT]\n'
	$(MAKE) clean -C $(LIBFTDIR)
	@printf '\n[PRINTF]\n'
	$(MAKE) clean -C $(PRINTFDIR)
	@printf '\n'

fclean:
	@printf '[BUFFER]\n'
	$(MAKE) fclean -C $(BUFFERDIR)
	@printf '\n[LIBFT]\n'
	$(MAKE) fclean -C $(LIBFTDIR)
	@printf '\n[PRINTF]\n'
	$(MAKE) fclean -C $(PRINTFDIR)
	@printf '\n'
	rm -f $(NAME)

re: fclean all

test: all
	@$(CC) $(CFLAGS) ./tests/printf.test.c -o test -L. -l:libftprintf.a
	@./test
	@rm -f ./test

.PHONY: all clean fclean re test buffer libft printf libs
