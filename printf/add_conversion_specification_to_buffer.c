/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_conversion_specification_to_buffer.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:13:47 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/13 01:13:31 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	add_conversion_specification_to_buffer(
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
		return (add_d_conversion_specification_to_buffer(buffer, args, specs));
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