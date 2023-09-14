/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:47:07 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/14 05:11:19 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	convert_s(
	va_list *args,
	t_buffer *conversion_buffer
){
	char	*arg;

	arg = va_arg(*args, char *);
	if (arg == 0)
	{
		if (add_cstring_to_buffer(conversion_buffer, "(null)") == ERROR)
			return (ERROR);
	}
	else
	{
		if (add_cstring_to_buffer(conversion_buffer, arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}