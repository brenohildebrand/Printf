/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:47:07 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/19 17:16:12 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	convert_s(
	va_list *args,
	t_buffer *conversion_buffer,
	t_conversion_specification *specs
){
	char	*arg;
	char	*substr;

	arg = va_arg(*args, char *);
	if (arg == 0)
	{
		if (add_cstring_to_buffer(conversion_buffer, "(null)") == ERROR)
			return (ERROR);
	}
	else
	{
		if (specs->precision >= 0)
		{
			substr = ft_substr(arg, 0, specs->precision);
			if (add_cstring_to_buffer(conversion_buffer, substr) == ERROR)
				return (ERROR);
			free(substr);
		}
		else
		{
			if (add_cstring_to_buffer(conversion_buffer, arg) == ERROR)
				return (ERROR);
		}
	}
	return (SUCCESS);
}
