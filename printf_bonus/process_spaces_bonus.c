/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_spaces_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:39:04 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/19 17:16:52 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	process_spaces(
	t_conversion_specification *specs,
	t_buffer *conversion_buffer
){
	int	i;

	if (
		((specs->flags & (1 << 3)) != 0) && \
		(specs->conversion_specifier == 'i' || \
			specs->conversion_specifier == 'd') && \
		conversion_buffer->current_length > 0 && \
		conversion_buffer->content[0] != '-')
		prepend_character_to_buffer(conversion_buffer, ' ');
	if ((long unsigned int)specs->minimum_field_width > \
	conversion_buffer->current_length)
	{
		i = specs->minimum_field_width - conversion_buffer->current_length;
		if (((specs->flags & (1 << 2)) != 0))
		{
			while (i--)
				append_character_to_buffer(conversion_buffer, ' ');
		}
		else
		{
			while (i--)
				prepend_character_to_buffer(conversion_buffer, ' ');
		}
	}
	return (SUCCESS);
}
