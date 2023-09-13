/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_p_conversion_specification_to_buffer.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:55:04 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/13 18:01:02 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	add_p_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
){
	void	*arg;
	char	*string;

	arg = va_arg(*args, void *);
	if (arg == 0)
		add_string_to_buffer(buffer, "(nil)");
	else
	{
		string = ft_unsigned_long_long_int_itoa_base((unsigned long long int)arg, HEX_LOWERCASE_BASE);
		if (string == NULL)
			return (ERROR);
		if (add_string_to_buffer(buffer, "0x") == ERROR)
			return (ERROR);
		if (add_string_to_buffer(buffer, string) == ERROR)
			return (ERROR);
		free(string);
	}
	return (SUCCESS);
}
