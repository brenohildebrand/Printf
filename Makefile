# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 15:30:27 by bhildebr          #+#    #+#              #
#    Updated: 2023/09/20 14:35:17 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

BUFFER_DIR = buffer
LIBFT_DIR = libft
PRINTF_DIR = printf

LIBBUFFER = $(BUFFER_DIR)/libbuffer.a
LIBFT = $(LIBFT_DIR)/libft.a
LIBPRINTF = $(PRINTF_DIR)/libprintf.a

HEADERS = \
	buffer.h \
	libft.h \
	printf.h

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

OBJECTS_BONUS = \
	buffer_bonus/add_buffer_to_buffer_bonus.o \
	buffer_bonus/add_character_to_buffer_bonus.o \
	buffer_bonus/add_cstring_to_buffer_bonus.o \
	buffer_bonus/add_unsigned_character_to_buffer_bonus.o \
	buffer_bonus/append_character_to_buffer_bonus.o \
	buffer_bonus/append_cstring_to_buffer_bonus.o \
	buffer_bonus/free_buffer_bonus.o \
	buffer_bonus/malloc_buffer_bonus.o \
	buffer_bonus/prepend_character_to_buffer_bonus.o \
	buffer_bonus/print_buffer_bonus.o \
	buffer_bonus/realloc_buffer_content_bonus.o \
	\
	libft_bonus/ft_atoi_bonus.o \
	libft_bonus/ft_bzero_bonus.o \
	libft_bonus/ft_calloc_bonus.o \
	libft_bonus/ft_int_itoa_base_bonus.o \
	libft_bonus/ft_isalnum_bonus.o \
	libft_bonus/ft_isalpha_bonus.o \
	libft_bonus/ft_isascii_bonus.o \
	libft_bonus/ft_isdigit_bonus.o \
	libft_bonus/ft_isprint_bonus.o \
	libft_bonus/ft_itoa_bonus.o \
	libft_bonus/ft_long_long_int_itoa_base_bonus.o \
	libft_bonus/ft_memchr_bonus.o \
	libft_bonus/ft_memcmp_bonus.o \
	libft_bonus/ft_memcpy_bonus.o \
	libft_bonus/ft_memmove_bonus.o \
	libft_bonus/ft_memset_bonus.o \
	libft_bonus/ft_putchar_fd_bonus.o \
	libft_bonus/ft_putendl_fd_bonus.o \
	libft_bonus/ft_putnbr_fd_bonus.o \
	libft_bonus/ft_putstr_fd_bonus.o \
	libft_bonus/ft_split_bonus.o \
	libft_bonus/ft_strchr_bonus.o \
	libft_bonus/ft_strdup_bonus.o \
	libft_bonus/ft_striteri_bonus.o \
	libft_bonus/ft_strjoin_bonus.o \
	libft_bonus/ft_strlcat_bonus.o \
	libft_bonus/ft_strlcpy_bonus.o \
	libft_bonus/ft_strlen_bonus.o \
	libft_bonus/ft_strmapi_bonus.o \
	libft_bonus/ft_strncmp_bonus.o \
	libft_bonus/ft_strnstr_bonus.o \
	libft_bonus/ft_strchr_bonus.o \
	libft_bonus/ft_strtrim_bonus.o \
	libft_bonus/ft_substr_bonus.o \
	libft_bonus/ft_tolower_bonus.o \
	libft_bonus/ft_toupper_bonus.o \
	libft_bonus/ft_unsigned_int_itoa_base_bonus.o \
	libft_bonus/ft_unsigned_long_long_int_itoa_base_bonus.o \
	\
	printf_bonus/add_conversion_specification_to_buffer_bonus.o \
	printf_bonus/convert_c_bonus.o \
	printf_bonus/convert_d_bonus.o \
	printf_bonus/convert_i_bonus.o \
	printf_bonus/convert_p_bonus.o \
	printf_bonus/convert_percentage_bonus.o \
	printf_bonus/convert_s_bonus.o \
	printf_bonus/convert_u_bonus.o \
	printf_bonus/convert_upper_x_bonus.o \
	printf_bonus/convert_x_bonus.o \
	printf_bonus/parse_conversion_specification_bonus.o \
	printf_bonus/parse_conversion_specifier_bonus.o \
	printf_bonus/parse_flags_bonus.o \
	printf_bonus/parse_formatted_string_bonus.o \
	printf_bonus/parse_minimum_field_width_bonus.o \
	printf_bonus/parse_precision_bonus.o \
	printf_bonus/printf_bonus.o \
	printf_bonus/process_alternate_form_bonus.o \
	printf_bonus/process_conversion_specifier_bonus.o \
	printf_bonus/process_signal_bonus.o \
	printf_bonus/process_spaces_bonus.o \
	printf_bonus/process_specs_bonus.o \
	printf_bonus/process_zeros_bonus.o

all: $(NAME)

$(NAME): $(OBJECTS)

bonus: $(OBJECTS_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

norm:
	@printf '[NORM]\n'
	@norminette -R CheckForbiddenSourceHeader
	@printf '\n'

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	@$(CC) $(CFLAGS) ./tests/printf.test.c -o test -L. -l:libftprintf.a
	@printf '[TEST]\n'
	@./test
	@rm -f ./test