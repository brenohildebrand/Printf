/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:14:38 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/11 17:12:14 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dependencies/Libft/libft.h"
#include "buffer.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_printf(const char *formatted_string, ...)
{
	va_list args;
	va_start(args, formatted_string);

	int		i;
	t_buffer	*buffer;

	if (formatted_string == NULL)
		return (ERROR);
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
			char	conversion_specifier_character;

			conversion_specifier_character = formatted_string[++i];
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
			if (conversion_specifier_character == 'c')
			{
				int	arg;
				
				arg = (char)va_arg(args, int);
				if (add_character_to_buffer(buffer, arg) == ERROR)
					return (ERROR);
			}
			else if (conversion_specifier_character == 's')
			{
				char	*arg;
				
				arg = va_arg(args, char *);
				while (*arg)
				{
					if (add_character_to_buffer(buffer, *arg) == ERROR)
						return (ERROR);
					arg++;
				}
			}
			else if (conversion_specifier_character == 'p')
			{
				void	*arg;
				
				arg = va_arg(args, void *);
				// itoa base 8 
			}
			else if (conversion_specifier_character == 'd')
			{
				
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
	print_buffer(buffer);
	free_buffer(buffer);
	return (0);
}