/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_s_conversion_specification_to_buffer.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:54:23 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/12 13:54:42 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "buffer.h"

#include <stdarg.h>

int	add_s_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
){
	char	*arg;
		
	arg = va_arg(*args, char *);
	while (*arg)
	{
		if (add_character_to_buffer(buffer, *arg) == ERROR)
			return (ERROR);
		arg++;
	}
	return (SUCCESS);
}