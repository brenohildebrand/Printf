/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_formatted_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:14:20 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/14 06:37:26 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	parse_formatted_string(
	const char *formatted_string,
	t_buffer *buffer,
	va_list *args
){
	t_conversion_specification	specs;
	int							i;

	i = 0;
	while (formatted_string[i])
	{
		if (formatted_string[i] == '%')
		{
			if (parse_conversion_specification(formatted_string, &i, &specs) == ERROR)
				return (ERROR);
			// printf("[DEBUG] Adding the following conversion specification to buffer:\n");
			// printf("[DEBUG] Specs:\n");
			// printf("[DEBUG] \tFlags:\t\t\t%i\n", specs.flags);
			// printf("[DEBUG] \tMinimum Width:\t\t%i\n", specs.minimum_field_width);
			// printf("[DEBUG] \tPrecision:\t\t%i\n", specs.precision);
			// printf("[DEBUG] \tConversion Specifier:\t%c\n", specs.conversion_specifier);
			if (add_conversion_specification_to_buffer(buffer, args, &specs) == ERROR)
				return (ERROR);
		}
		else
		{
			// printf("[DEBUG] Adding the character '%c' to buffer.\n", formatted_string[i]);
			if (add_character_to_buffer(buffer, formatted_string[i]) == ERROR)
				return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}
