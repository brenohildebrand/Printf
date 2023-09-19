# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 12:59:56 by bhildebr          #+#    #+#              #
#    Updated: 2023/09/19 17:22:54 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = \
	add_conversion_specification_to_buffer_bonus.c \
	convert_c_bonus.c \
	convert_d_bonus.c \
	convert_i_bonus.c \
	convert_p_bonus.c \
	convert_percentage_bonus.c \
	convert_s_bonus.c \
	convert_u_bonus.c \
	convert_upper_x_bonus.c \
	convert_x_bonus.c \
	parse_conversion_specification_bonus.c \
	parse_conversion_specifier_bonus.c \
	parse_flags_bonus.c \
	parse_formatted_string_bonus.c \
	parse_minimum_field_width_bonus.c \
	parse_precision_bonus.c \
	printf_bonus.c \
	process_alternate_form_bonus.c \
	process_conversion_specifier_bonus.c \
	process_signal_bonus.c \
	process_spaces_bonus.c \
	process_specs_bonus.c \
	process_zeros_bonus.c

HEADERS = \
	printf_bonus.h

OBJECTS = \
	add_conversion_specification_to_buffer_bonus.o \
	convert_c_bonus.o \
	convert_d_bonus.o \
	convert_i_bonus.o \
	convert_p_bonus.o \
	convert_percentage_bonus.o \
	convert_s_bonus.o \
	convert_u_bonus.o \
	convert_upper_x_bonus.o \
	convert_x_bonus.o \
	parse_conversion_specification_bonus.o \
	parse_conversion_specifier_bonus.o \
	parse_flags_bonus.o \
	parse_formatted_string_bonus.o \
	parse_minimum_field_width_bonus.o \
	parse_precision_bonus.o \
	printf_bonus.o \
	process_alternate_form_bonus.o \
	process_conversion_specifier_bonus.o \
	process_signal_bonus.o \
	process_spaces_bonus.o \
	process_specs_bonus.o \
	process_zeros_bonus.o

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADERS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re