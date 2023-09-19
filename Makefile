# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 15:30:27 by bhildebr          #+#    #+#              #
#    Updated: 2023/09/19 17:50:39 by bhildebr         ###   ########.fr        #
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

clean: clean_bonus
	@printf '[BUFFER]\n'
	$(MAKE) clean -C $(BUFFERDIR)
	@printf '\n[LIBFT]\n'
	$(MAKE) clean -C $(LIBFTDIR)
	@printf '\n[PRINTF]\n'
	$(MAKE) clean -C $(PRINTFDIR)
	@printf '\n'

fclean: fclean_bonus
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

# BONUS
NAME_BONUS = libftprintf.a

BUFFERDIR_BONUS = buffer_bonus
LIBFTDIR_BONUS = libft_bonus
PRINTFDIR_BONUS = printf_bonus

LIBBUFFER_BONUS = $(BUFFERDIR_BONUS)/libbuffer.a
LIBFT_BONUS = $(LIBFTDIR_BONUS)/libft.a
LIBPRINTF_BONUS = $(PRINTFDIR_BONUS)/libprintf.a

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

bonus: norm_bonus libs_bonus $(NAME_BONUS)

$(NAME_BONUS): $(OBJECTS_BONUS)
	ar rcs $(NAME_BONUS) $(OBJECTS_BONUS)

norm_bonus:
	@printf '[NORM]\n'
	@norminette
	@printf '\n'

libs_bonus: buffer_bonus libft_bonus printf_bonus

buffer_bonus:
	@printf '[BUFFER]\n'
	$(MAKE) all -C $(BUFFERDIR_BONUS)

libft_bonus:
	@printf '\n[LIBFT]\n'
	$(MAKE) all -C $(LIBFTDIR_BONUS)
	
printf_bonus:
	@printf '\n[PRINTF]\n'
	$(MAKE) all -C $(PRINTFDIR_BONUS)
	@printf '\n'

clean_bonus:
	@printf '[BUFFER]\n'
	$(MAKE) clean -C $(BUFFERDIR_BONUS)
	@printf '\n[LIBFT]\n'
	$(MAKE) clean -C $(LIBFTDIR_BONUS)
	@printf '\n[PRINTF]\n'
	$(MAKE) clean -C $(PRINTFDIR_BONUS)
	@printf '\n'

fclean_bonus:
	@printf '[BUFFER]\n'
	$(MAKE) fclean -C $(BUFFERDIR_BONUS)
	@printf '\n[LIBFT]\n'
	$(MAKE) fclean -C $(LIBFTDIR_BONUS)
	@printf '\n[PRINTF]\n'
	$(MAKE) fclean -C $(PRINTFDIR_BONUS)
	@printf '\n'
	rm -f $(NAME_BONUS)

re_bonus: fclean_bonus bonus

.PHONY: \
	all bonus \
	clean clean_bonus \
	fclean fclean_bonus \
	re re_bonus \
	test \
	buffer buffer_bonus \
	libft libft_bonus \
	printf printf_bonus \
	libs libs_bonus
