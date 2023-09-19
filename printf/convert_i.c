/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:50:16 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/18 21:54:47 by bhildebr         ###   ########.fr       */
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
	cstring = ft_int_itoa_base(arg, DEC_BASE);
	if (cstring == NULL)
		return (ERROR);
	if (add_cstring_to_buffer(conversion_buffer, cstring) == ERROR)
		return (ERROR);
	free(cstring);
	return (SUCCESS);
}
