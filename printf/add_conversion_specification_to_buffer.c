/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_conversion_specification_to_buffer.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:13:47 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/15 14:35:53 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	add_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
){
	t_buffer	*conversion_buffer;

	if (malloc_buffer(&conversion_buffer) == ERROR)
	{
		return (ERROR);
	}
	if (process_specs(args, specs, conversion_buffer) == ERROR)
	{
		free_buffer(conversion_buffer);
		return (ERROR);
	}
	if (add_buffer_to_buffer(buffer, conversion_buffer) == ERROR)
	{
		return (ERROR);
	}
	free_buffer(conversion_buffer);
	return (SUCCESS);
}
