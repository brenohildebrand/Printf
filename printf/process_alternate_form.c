/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_alternate_form.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:55:12 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/16 16:07:59 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	process_alternate_form(t_conversion_specification *specs, t_buffer *conversion_buffer)
{
	if (HASH_IS_ON(specs->flags))
	{
		if (specs->conversion_specifier == 'x')
		{
			prepend_character_to_buffer(conversion_buffer, 'x');
			prepend_character_to_buffer(conversion_buffer, '0');
		}
		if (specs->conversion_specifier == 'X')
		{
			prepend_character_to_buffer(conversion_buffer, 'X');
			prepend_character_to_buffer(conversion_buffer, '0');
		}
	}
	return (SUCCESS);
}