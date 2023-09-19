# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 12:54:22 by bhildebr          #+#    #+#              #
#    Updated: 2023/09/19 17:21:06 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = \
	ft_atoi_bonus.c \
	ft_bzero_bonus.c \
	ft_calloc_bonus.c \
	ft_int_itoa_base_bonus.c \
	ft_isalnum_bonus.c \
	ft_isalpha_bonus.c \
	ft_isascii_bonus.c \
	ft_isdigit_bonus.c \
	ft_isprint_bonus.c \
	ft_itoa_bonus.c \
	ft_long_long_int_itoa_base_bonus.c \
	ft_memchr_bonus.c \
	ft_memcmp_bonus.c \
	ft_memcpy_bonus.c \
	ft_memmove_bonus.c \
	ft_memset_bonus.c \
	ft_putchar_fd_bonus.c \
	ft_putendl_fd_bonus.c \
	ft_putnbr_fd_bonus.c \
	ft_putstr_fd_bonus.c \
	ft_split_bonus.c \
	ft_strchr_bonus.c \
	ft_strdup_bonus.c \
	ft_striteri_bonus.c \
	ft_strjoin_bonus.c \
	ft_strlcat_bonus.c \
	ft_strlcpy_bonus.c \
	ft_strlen_bonus.c \
	ft_strmapi_bonus.c \
	ft_strncmp_bonus.c \
	ft_strnstr_bonus.c \
	ft_strchr_bonus.c \
	ft_strtrim_bonus.c \
	ft_substr_bonus.c \
	ft_tolower_bonus.c \
	ft_toupper_bonus.c \
	ft_unsigned_int_itoa_base_bonus.c \
	ft_unsigned_long_long_int_itoa_base_bonus.c

HEADERS = \
	libft_bonus.h

OBJECTS = \
	ft_atoi_bonus.o \
	ft_bzero_bonus.o \
	ft_calloc_bonus.o \
	ft_int_itoa_base_bonus.o \
	ft_isalnum_bonus.o \
	ft_isalpha_bonus.o \
	ft_isascii_bonus.o \
	ft_isdigit_bonus.o \
	ft_isprint_bonus.o \
	ft_itoa_bonus.o \
	ft_long_long_int_itoa_base_bonus.o \
	ft_memchr_bonus.o \
	ft_memcmp_bonus.o \
	ft_memcpy_bonus.o \
	ft_memmove_bonus.o \
	ft_memset_bonus.o \
	ft_putchar_fd_bonus.o \
	ft_putendl_fd_bonus.o \
	ft_putnbr_fd_bonus.o \
	ft_putstr_fd_bonus.o \
	ft_split_bonus.o \
	ft_strchr_bonus.o \
	ft_strdup_bonus.o \
	ft_striteri_bonus.o \
	ft_strjoin_bonus.o \
	ft_strlcat_bonus.o \
	ft_strlcpy_bonus.o \
	ft_strlen_bonus.o \
	ft_strmapi_bonus.o \
	ft_strncmp_bonus.o \
	ft_strnstr_bonus.o \
	ft_strchr_bonus.o \
	ft_strtrim_bonus.o \
	ft_substr_bonus.o \
	ft_tolower_bonus.o \
	ft_toupper_bonus.o \
	ft_unsigned_int_itoa_base_bonus.o \
	ft_unsigned_long_long_int_itoa_base_bonus.o

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADERS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re