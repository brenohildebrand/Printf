/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:36:48 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/19 17:15:57 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	convert_c(
	va_list	*args,
	t_buffer *conversion_buffer
){
	unsigned char	arg;

	arg = (unsigned char)va_arg(*args, int);
	if (add_unsigned_character_to_buffer(conversion_buffer, arg) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
