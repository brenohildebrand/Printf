/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:14:38 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/12 01:50:08 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dependencies/Libft/libft.h"
#include "buffer.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_conversion_specification
{
	int		flags;
	int		precision;
	int		minimum_field_width;
	int		length_modifier;
	char	conversion_specifier;
}	t_conversion_specification;

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
	char *formatted_string,
	int *i,
	t_conversion_specification *specs
){
	specs->conversion_specifier = formatted_string[++(*i)];
}

static int	add_c_conversion_specification_to_buffer(
	t_conversion_specification *specs,
	va_list *args
){
	int	arg;
		
	arg = (char)va_arg(args, int);
	if (add_character_to_buffer(buffer, arg) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static int	add_s_conversion_specification_to_buffer(
	t_conversion_specification *specs,
	va_list *args
){
	char	*arg;
		
	arg = va_arg(args, char *);
	while (*arg)
	{
		if (add_character_to_buffer(buffer, *arg) == ERROR)
			return (ERROR);
		arg++;
	}
	return (SUCCESS);
}

static int	add_p_conversion_specification_to_buffer(
	t_conversion_specification *specs,
	va_list *args
){
	void	*arg;
	char	*string;

	arg = va_arg(args, void *);
	string = ft_itoa_base((int)arg, "0123456789abcdef");
	if (string == NULL)
		return (ERROR);
	while (*string)
	{
		if (add_character_to_buffer(buffer, *string) == ERROR)
			return (ERROR);
		string++;
	}
	free(string);
	return (SUCCESS);
}

static int	add_d_conversion_specification_to_buffer(
	t_conversion_specification *specs,
	va_list *args
){
	
}

static int	add_conversion_specification_to_buffer(
	t_conversion_specification *specs, 
	va_list *args
){
	if (specs->conversion_specifier == 'c')
		return (add_c_conversion_specification_to_buffer(specs, args));
	else if (specs->conversion_specifier == 's')
		return (add_s_conversion_specification_to_buffer(specs, args));
	else if (specs->conversion_specifier == 'p')
		return (add_p_conversion_specification_to_buffer(specs, args));
	else if (specs->conversion_specifier == 'd')
		return (add_p_conversion_specification_to_buffer(specs, args));
}

int ft_printf(const char *formatted_string, ...)
{
	va_list		args;
	t_buffer	*buffer;
	int			i;
	
	va_start(args, formatted_string);
	if (formatted_string == NULL)
		return (ERROR);
	if (malloc_buffer(&buffer) == ERROR)
		return (ERROR);
	i = 0;
	while(formatted_string[i])
	{
		if (formatted_string[i] == '%')
		{
			t_conversion_specification specs;
			if (parse_conversion_specification(formatted_string, &i, &specs) == ERROR)
			{
				free_buffer(buffer);
				return (ERROR);
			}
			if (add_conversion_specification_to_buffer(&specs, &args) == ERROR)
			{
				free_buffer(buffer);
				return (ERROR);
			}
		}
		else
		{
			if (add_character_to_buffer(buffer, formatted_string[i]) == ERROR)
			{
				free_buffer(buffer);
				return (ERROR);
			}
		}
		i++;
	}
	va_end(args);
	print_buffer(buffer);
	free_buffer(buffer);
	return (0);
}