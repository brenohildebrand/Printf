/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:52:11 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/14 05:10:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	convert_p(
	va_list *args,
	t_buffer *conversion_buffer
){
	void	*arg;
	char	*cstring;

	arg = va_arg(*args, void *);
	if (arg == 0)
	{
		if (add_cstring_to_buffer(conversion_buffer, "(nil)") == ERROR)
			return (ERROR);
	}
	else
	{
		cstring = ft_unsigned_long_long_int_itoa_base((unsigned long long int)arg, HEX_LOWERCASE_BASE);
		if (cstring == NULL)
			return (ERROR);
		if (add_cstring_to_buffer(conversion_buffer, "0x") == ERROR)
			return (ERROR);
		if (add_cstring_to_buffer(conversion_buffer, cstring) == ERROR)
			return (ERROR);
		free(cstring);
	}
	return (SUCCESS);
}