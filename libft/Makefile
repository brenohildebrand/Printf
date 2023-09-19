# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 12:54:22 by bhildebr          #+#    #+#              #
#    Updated: 2023/09/19 13:02:32 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_int_itoa_base.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_long_long_int_itoa_base.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_unsigned_int_itoa_base.c \
	ft_unsigned_long_long_int_itoa_base.c

HEADERS = \
	libft.h

OBJECTS = \
	ft_atoi.o \
	ft_bzero.o \
	ft_calloc.o \
	ft_int_itoa_base.o \
	ft_isalnum.o \
	ft_isalpha.o \
	ft_isascii.o \
	ft_isdigit.o \
	ft_isprint.o \
	ft_itoa.o \
	ft_long_long_int_itoa_base.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_memcpy.o \
	ft_memmove.o \
	ft_memset.o \
	ft_putchar_fd.o \
	ft_putendl_fd.o \
	ft_putnbr_fd.o \
	ft_putstr_fd.o \
	ft_split.o \
	ft_strchr.o \
	ft_strdup.o \
	ft_striteri.o \
	ft_strjoin.o \
	ft_strlcat.o \
	ft_strlcpy.o \
	ft_strlen.o \
	ft_strmapi.o \
	ft_strncmp.o \
	ft_strnstr.o \
	ft_strchr.o \
	ft_strtrim.o \
	ft_substr.o \
	ft_tolower.o \
	ft_toupper.o \
	ft_unsigned_int_itoa_base.o \
	ft_unsigned_long_long_int_itoa_base.o

DEPENDS = \
	ft_atoi.d \
	ft_bzero.d \
	ft_calloc.d \
	ft_int_itoa_base.d \
	ft_isalnum.d \
	ft_isalpha.d \
	ft_isascii.d \
	ft_isdigit.d \
	ft_isprint.d \
	ft_itoa.d \
	ft_long_long_int_itoa_base.d \
	ft_memchr.d \
	ft_memcmp.d \
	ft_memcpy.d \
	ft_memmove.d \
	ft_memset.d \
	ft_putchar_fd.d \
	ft_putendl_fd.d \
	ft_putnbr_fd.d \
	ft_putstr_fd.d \
	ft_split.d \
	ft_strchr.d \
	ft_strdup.d \
	ft_striteri.d \
	ft_strjoin.d \
	ft_strlcat.d \
	ft_strlcpy.d \
	ft_strlen.d \
	ft_strmapi.d \
	ft_strncmp.d \
	ft_strnstr.d \
	ft_strchr.d \
	ft_strtrim.d \
	ft_substr.d \
	ft_tolower.d \
	ft_toupper.d \
	ft_unsigned_int_itoa_base.d \
	ft_unsigned_long_long_int_itoa_base.d

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADERS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re