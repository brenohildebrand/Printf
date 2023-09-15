/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:50:16 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/15 11:04:22 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	convert_i(
	va_list *args,
	t_buffer *conversion_buffer
){
	int		arg;
	char	*cstring;

	arg = va_arg(*args, int);
	
	// convert specifier
	cstring = ft_int_itoa_base(arg, DEC_BASE);
	if (cstring == NULL)
		return (ERROR);

	// value and precision
	if (precision <= ft_strlen(cstring))
	{
		cstring = ft_substr(cstring, 0, precision);
		append_cstring_to_buffer(conversion_buffer, cstring);
	}
	else
	{
		append_cstring_to_buffer(conversion_buffer, cstring);
		int nzeros = ft_strlen(cstring) - precision;
		while (nzeros--)
		{
			prepend_character_to_buffer(conversion_buffer, '0');
		}
	}

	// alternate form (does not apply)
	

	if (add_cstring_to_buffer(conversion_buffer, cstring) == ERROR)
		return (ERROR);
	free(cstring);

	// value -> precision (only change the value) -> alternate form -> padding (consider the side) -> signal -> margin (padding is between the signal and the margin)
	
	return (SUCCESS);
}
