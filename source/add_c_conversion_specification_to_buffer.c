/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_c_conversion_specification_to_buffer.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:48:56 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/12 16:54:08 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "buffer.h"

#include <stdarg.h>

int	add_c_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
){
	int		arg;
	char	*string;

	arg = (char)va_arg(*args, int);
	if (add_character_to_buffer(buffer, arg) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
