# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 12:59:56 by bhildebr          #+#    #+#              #
#    Updated: 2023/09/19 13:09:11 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = \
	add_conversion_specification_to_buffer.c \
	convert_c.c \
	convert_d.c \
	convert_i.c \
	convert_p.c \
	convert_percentage.c \
	convert_s.c \
	convert_u.c \
	convert_upper_x.c \
	convert_x.c \
	parse_conversion_specification.c \
	parse_conversion_specifier.c \
	parse_flags.c \
	parse_formatted_string.c \
	parse_minimum_field_width.c \
	parse_precision.c \
	printf.c \
	process_alternate_form.c \
	process_conversion_specifier.c \
	process_signal.c \
	process_spaces.c \
	process_specs.c \
	process_zeros.c

HEADERS = \
	printf.h

OBJECTS = \
	add_conversion_specification_to_buffer.o \
	convert_c.o \
	convert_d.o \
	convert_i.o \
	convert_p.o \
	convert_percentage.o \
	convert_s.o \
	convert_u.o \
	convert_upper_x.o \
	convert_x.o \
	parse_conversion_specification.o \
	parse_conversion_specifier.o \
	parse_flags.o \
	parse_formatted_string.o \
	parse_minimum_field_width.o \
	parse_precision.o \
	printf.o \
	process_alternate_form.o \
	process_conversion_specifier.o \
	process_signal.o \
	process_spaces.o \
	process_specs.o \
	process_zeros.o

DEPENDS = \
	add_conversion_specification_to_buffer.d \
	convert_c.d \
	convert_d.d \
	convert_i.d \
	convert_p.d \
	convert_percentage.d \
	convert_s.d \
	convert_u.d \
	convert_upper_x.d \
	convert_x.d \
	parse_conversion_specification.d \
	parse_conversion_specifier.d \
	parse_flags.d \
	parse_formatted_string.d \
	parse_minimum_field_width.d \
	parse_precision.d \
	printf.d \
	process_alternate_form.d \
	process_conversion_specifier.d \
	process_signal.d \
	process_spaces.d \
	process_specs.d \
	process_zeros.d

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADERS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re