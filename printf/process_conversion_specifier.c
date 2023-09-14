/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_conversion_specifier.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:52:18 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/14 06:35:32 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include <stdarg.h>

int	process_conversion_specifier(
	t_conversion_specification *specs,
	va_list	*args,
	t_buffer *conversion_buffer
){
	if (specs->conversion_specifier == 'c')
		return (convert_c(args, conversion_buffer));
	else if (specs->conversion_specifier == 's')
		return (convert_s(args, conversion_buffer));
	else if (specs->conversion_specifier == 'p')
		return (convert_p(args, conversion_buffer));
	else if (specs->conversion_specifier == 'd')
		return (convert_d(args, conversion_buffer));
	else if (specs->conversion_specifier == 'i')
		return (convert_i(args, conversion_buffer));
	else if (specs->conversion_specifier == 'u')
		return (convert_u(args, conversion_buffer));
	else if (specs->conversion_specifier == 'x')
		return (convert_x(args, conversion_buffer));
	else if (specs->conversion_specifier == 'X')
		return (convert_upper_x(args, conversion_buffer));
	else if (specs->conversion_specifier == '%')
		return (convert_percentage(args, conversion_buffer));
	else
		return (ERROR);
}
