/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:50:16 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/16 12:38:20 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	convert_x(
	va_list *args,
	t_buffer *conversion_buffer,
	t_conversion_specification *specs
){
	unsigned int	arg;
	char			*cstring;

	arg = va_arg(*args, unsigned int);
	cstring = ft_unsigned_int_itoa_base(arg, HEX_LOWERCASE_BASE);
	if (cstring == NULL)
		return (ERROR);
	if (add_cstring_to_buffer(conversion_buffer, cstring) == ERROR)
		return (ERROR);
	free(cstring);
	return (SUCCESS);
}
