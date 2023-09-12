/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:14:38 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/12 17:14:54 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dependencies/Libft/libft.h"

#include "printf.h"
#include "buffer.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * %
 * zero or more flags
 * an optional minimum field width
 * an optional precision
 * an optional length modifier
 * conversion specifier
*/
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

static int	parse_conversion_specification(
	const char *formatted_string,
	int *i,
	t_conversion_specification *specs
){
	char	current_character;

	// go through flags
	specs->flags = 0;
	while (1)
	{
		current_character = formatted_string[++(*i)];
		if (current_character == FLAGS[0] /* && ainda nn ta setado */)
			specs->flags |= 1 << 0;
		else if (current_character == FLAGS[1] /* && ainda nn ta setado */)
			specs->flags |= 1 << 1;
		else if (current_character == FLAGS[2] /* && ainda nn ta setado */)
			specs->flags |= 1 << 2;
		else if (current_character == FLAGS[3] /* && ainda nn ta setado */)
			specs->flags |= 1 << 3;
		else if (current_character == FLAGS[4] /* && ainda nn ta setado */)
			specs->flags |= 1 << 4;
		else
			break;
	}

	// check for optional minimum field
	specs->minimum_field_width = 0;
	current_character = formatted_string[++(*i)];
	if (ft_isdigit(current_character) && current_character != '0')
	{
		while(ft_isdigit(current_character))
		{
			specs->minimum_field_width *= 10;
			specs->minimum_field_width += (int)(current_character - '0');
			current_character = formatted_string[++(*i)];
		}
	}
	
	// check for optional precision
	specs->precision = 0;
	if (current_character == '.')
	{
		current_character = formatted_string[++(*i)];
		while(ft_isdigit(current_character))
		{
			specs->precision *= 10;
			specs->precision += (int)(current_character - '0');
			current_character = formatted_string[++(*i)];
		}
	}

	// don't check for optional length modifier

	// check for conversion specifier
	if (ft_strchr(CONVERSION_SPECIFIERS, current_character) == -1)
		return (ERROR);
	else
		specs->conversion_specifier = current_character;

	return (SUCCESS);
}

static int	add_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
){
	if (specs->conversion_specifier == 'c')
		return (add_c_conversion_specification_to_buffer(buffer, args, specs));
	else if (specs->conversion_specifier == 's')
		return (add_s_conversion_specification_to_buffer(buffer, args, specs));
	else if (specs->conversion_specifier == 'p')
		return (add_p_conversion_specification_to_buffer(buffer, args, specs));
	else if (specs->conversion_specifier == 'd')
		return (add_p_conversion_specification_to_buffer(buffer, args, specs));
	else if (specs->conversion_specifier == 'i')
		return (add_i_conversion_specification_to_buffer(buffer, args, specs));
	else if (specs->conversion_specifier == 'u')
		return (add_u_conversion_specification_to_buffer(buffer, args, specs));
	else if (specs->conversion_specifier == 'x')
		return (add_x_conversion_specification_to_buffer(buffer, args, specs));
	else if (specs->conversion_specifier == 'X')
		return (add_upper_x_conversion_specification_to_buffer(buffer, args, specs));
	else if (specs->conversion_specifier == '%')
		return (add_percentage_conversion_specification_to_buffer(buffer, args, specs));
	else
		return (ERROR);
}

static int parse_formatted_string(
	const char *formatted_string,
	t_buffer *buffer,
	va_list *args
){
	t_conversion_specification	specs;
	int							i;

	i = 0;
	while(formatted_string[i])
	{
		if (formatted_string[i] == '%')
		{
			if (parse_conversion_specification(formatted_string, &i, &specs) == ERROR)
				return (ERROR);
			if (add_conversion_specification_to_buffer(buffer, args, &specs) == ERROR)
				return (ERROR);
		}
		else
		{
			if (add_character_to_buffer(buffer, formatted_string[i]) == ERROR)
				return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int ft_printf(const char *formatted_string, ...)
{
	t_buffer	*buffer;
	va_list		args;
	
	if (formatted_string == NULL)
		return (ERROR);
	if (malloc_buffer(&buffer) == ERROR)
		return (ERROR);
	va_start(args, formatted_string);
	if (parse_formatted_string(formatted_string, buffer, &args) == ERROR)
	{
		free_buffer(buffer);
		return (ERROR);
	}
	va_end(args);
	print_buffer(buffer);
	free_buffer(buffer);
	return (0);
}