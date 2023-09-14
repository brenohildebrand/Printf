/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_conversion_specification_to_buffer.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:13:47 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/13 22:05:54 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../string/ft_string.h"

int	add_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
){
	t_string	*string;

	if (specs->conversion_specifier == '%')
	{
		add_character_to_buffer(buffer, '%');
		return (SUCCESS);		
	}
	if (malloc_string(&string) == ERROR)
		return (ERROR);
	if (process_conversion_specifier(specs, args, &string) == ERROR)
	{
		free_string(string);
		return (ERROR);
	}
	if (process_precision(specs, &string) == ERROR)
	{
		free_string(string);
		return (ERROR);
	}
	if (process_hash_flag(specs, &string) == ERROR)
	{
		free_string(string);
		return (ERROR);	
	}
	if (process_space_flag(specs, &string) == ERROR)
	{
		free_string(string);
		return (ERROR);
	}
	if (process_sign_flag(specs, &string) == ERROR)
	{
		free_string(string);
		return (ERROR);
	}
	if (process_minimum_field_width(specs, &string) == ERROR)
	{
		free_string(string);
		return (ERROR);
	}
	if (add_string_to_buffer(buffer, string) == ERROR)
		return (ERROR);
	free_string(string);
	return (SUCCESS);
}