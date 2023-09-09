/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:14:38 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/09 17:00:54 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define SUCCESS 0
#define ERROR -1

typedef struct s_buffer {
	size_t	current_length;
	size_t	max_length;
	size_t	start_index;
	size_t	last_index;
	char	*content;
}	t_buffer;

int	*malloc_buffer(t_buffer **buffer_address)
{
	*buffer_address = malloc(sizeof(t_buffer));
	if (*buffer_address == NULL)
		return (ERROR);
	(*buffer_address)->content = (char *)malloc(1 * sizeof(char));
	if ((*buffer_address)->content == NULL)
		return (ERROR);
	(*buffer_address)->current_length = 0;
	(*buffer_address)->max_length = 1;
	(*buffer_address)->start_index = 0;
	(*buffer_address)->last_index = 0;
	return (SUCCESS);
}

int	*realloc_buffer_content(t_buffer *buffer, size_t original_length, size_t new_length)
{
	char	*new_content;
	int		i;

	new_content = (char *)malloc(new_length);
	if (new_content == NULL)
		return (ERROR);
	i = 0;
	while (i < original_length)
	{	
		new_content[i] = buffer->content[i];
		i++;
	}
	free(buffer->content);
	buffer->content = new_content;
	return (SUCCESS);
}

int	free_buffer(t_buffer *buffer)
{
	free(buffer->content);
	free(buffer);
	return (SUCCESS);
}

int	add_character_to_buffer(t_buffer *buffer, char character)
{
	if (buffer->current_length + 1 > buffer->max_length)
	{
		if (realloc_buffer_content(buffer, buffer->max_length, buffer->max_length * 2) == ERROR)
			return (ERROR);
	}
	buffer->content[buffer->last_index++] = character;
	return (SUCCESS);
}

int	add_string_to_buffer(t_buffer *buffer, char *cstring)
{
	if (buffer->current_length + ft_strlen(cstring) > buffer->max_length)
	{
		// do some math here and create the math functions on libft
		// realloc accordingly
	}
	while ((*cstring)++)
		buffer->content[buffer->last_index++];
	return (SUCCESS);
}

int ft_printf(const char *formatted_string, ...)
{
	int		i;
	t_buffer	*buffer;

	if (malloc_buffer(&buffer) == ERROR)
		return (ERROR);
	i = 0;
	while(formatted_string[i])
	{
		if (formatted_string[i] == '%')
		{
			/**
			 * %
			 * zero or more flags
			 * an optional minimum field width
			 * an optional precision
			 * an optional length modifier
			 * conversion specifier
			*/
			parse_conversion_specification(flags, field_width, precision, length_modifier);

			/**
			 * Conversion Specifiers
			 * %c Prints a single character.
			 * %s Prints a string (as defined by the common C convention).
			 * %p The void * pointer argument has to be printed in hexadecimal format.
			 * %d Prints a decimal (base 10) number.
			 * %i Prints an integer in base 10.
			 * %u Prints an unsigned decimal (base 10) number.
			 * %x Prints a number in hexadecimal (base 16) lowercase format.
			 * %X Prints a number in hexadecimal (base 16) uppercase format.
			 * %% Prints a percent sign.
			*/
		}
		else
		{
			if (add_character_to_buffer(buffer, formatted_string[i]) != NULL)
			{
				free_buffer(buffer);
				return (ERROR);
			}
		}
		i++;
	}

	return (0);
}