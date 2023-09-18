/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:14:38 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/18 01:22:12 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *formatted_string, ...)
{
	t_buffer		*buffer;
	va_list			args;
	unsigned long	len;

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
	len = buffer->current_length;
	free_buffer(buffer);
	return (len);
}
