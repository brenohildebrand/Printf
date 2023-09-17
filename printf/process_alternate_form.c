/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_alternate_form.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:55:12 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/17 01:16:09 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	is_non_zero(t_buffer *conversion_buffer)
{
	int	i;

	i = 0;
	while (i < conversion_buffer->current_length)
	{
		if (conversion_buffer->content[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	process_alternate_form(t_conversion_specification *specs, t_buffer *conversion_buffer)
{
	if (HASH_IS_ON(specs->flags))
	{
		if (specs->conversion_specifier == 'x' && is_non_zero(conversion_buffer))
		{
			prepend_character_to_buffer(conversion_buffer, 'x');
			prepend_character_to_buffer(conversion_buffer, '0');
		}
		if (specs->conversion_specifier == 'X' && is_non_zero(conversion_buffer))
		{
			prepend_character_to_buffer(conversion_buffer, 'X');
			prepend_character_to_buffer(conversion_buffer, '0');
		}
	}
	return (SUCCESS);
}