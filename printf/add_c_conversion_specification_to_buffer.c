/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_c_conversion_specification_to_buffer.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:48:56 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/13 20:15:37 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	process_flags(int flags, char **string_address)
{
	

	return (SUCCESS);
}

int	add_c_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
){
	int		arg;
	char	*string;

	arg = (char)va_arg(*args, int);
	string = malloc((1 + 1) * sizeof(char));
	string[0] = arg;
	string[1] = '\0';
	if (process_flags(specs->flags, &string) == ERROR)
		return (ERROR);
	if (add_string_to_buffer(buffer, string) == ERROR)
		return (ERROR);	
	return (SUCCESS);
}
