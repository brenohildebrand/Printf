/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepend_character_to_buffer_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:41:56 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/19 17:13:21 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_bonus.h"

int	prepend_character_to_buffer(t_buffer *buffer, char character)
{
	int	i;

	if (buffer->current_length + 1 > buffer->max_length)
	{
		if (realloc_buffer_content(
				buffer,
				buffer->max_length,
				buffer->max_length * 2) == ERROR)
			return (ERROR);
	}
	i = buffer->current_length;
	while (i >= 1)
	{
		buffer->content[i] = buffer->content[i - 1];
		i--;
	}
	buffer->content[0] = character;
	buffer->current_length++;
	return (SUCCESS);
}
