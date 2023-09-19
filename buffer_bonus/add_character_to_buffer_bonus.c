/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_character_to_buffer_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:33:42 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/19 17:13:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_bonus.h"

int	add_character_to_buffer(t_buffer *buffer, char character)
{
	if (buffer->current_length + 1 > buffer->max_length)
	{
		if (realloc_buffer_content(
				buffer,
				buffer->max_length,
				buffer->max_length * 2) == ERROR)
			return (ERROR);
	}
	buffer->content[buffer->current_length++] = character;
	return (SUCCESS);
}
