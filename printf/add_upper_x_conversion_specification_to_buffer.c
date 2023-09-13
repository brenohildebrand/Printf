/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_upper_x_conversion_specification_to_buf        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:00:39 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/13 18:08:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	add_upper_x_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
){
	unsigned int	arg;
	char			*string;

	arg = va_arg(*args, unsigned int);
	string = ft_unsigned_int_itoa_base(arg, HEX_UPPERCASE_BASE);
	if (string == NULL)
		return (ERROR);
	if (add_string_to_buffer(buffer, string) == ERROR)
		return (ERROR);
	free(string);
	return (SUCCESS);
}
