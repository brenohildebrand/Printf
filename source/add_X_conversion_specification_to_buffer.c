/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_X_conversion_specification_to_buffer.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:00:39 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/12 14:29:28 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dependencies/Libft/libft.h"

#include "printf.h"
#include "buffer.h"

#include <stdarg.h>

int	add_X_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
){
	int		arg;
	char	*string;

	arg = va_arg(*args, int);
	string = ft_itoa_base((int)arg, HEX_UPPERCASE_BASE);
	if (string == NULL)
		return (ERROR);
	if (add_string_to_buffer(buffer, string) == ERROR)
		return (ERROR);
	free(string);
	return (SUCCESS);
}