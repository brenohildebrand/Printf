/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_buffer_to_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:24:41 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/14 03:51:13 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

int	add_buffer_to_buffer(t_buffer *buffer, t_buffer *source_buffer)
{
	unsigned long	i;

	i = 0;
	while (i < source_buffer->current_length)
	{
		if (add_character_to_buffer(buffer, source_buffer->content[i]) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
