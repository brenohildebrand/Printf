/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_formatted_string_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:14:20 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/19 17:16:33 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

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
			if (parse_conversion_specification(
					formatted_string, &i, &specs) == ERROR)
				return (ERROR);
			if (add_conversion_specification_to_buffer(
					buffer, args, &specs) == ERROR)
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
