/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:16:09 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/11 20:42:59 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "../dependencies/Libft/libft.h"

int	malloc_buffer(t_buffer **buffer_address)
{
	*buffer_address = malloc(sizeof(t_buffer));
	if (*buffer_address == NULL)
		return (ERROR);
	(*buffer_address)->content = (char *)malloc(1 * sizeof(char));
	if ((*buffer_address)->content == NULL)
		return (ERROR);
	(*buffer_address)->current_length = 0;
	(*buffer_address)->max_length = 1;
	return (SUCCESS);
}

int	realloc_buffer_content(\
t_buffer *buffer, \
unsigned long original_length, \
unsigned long new_length)
{
	char			*new_content;
	unsigned long	i;

	new_content = (char *)malloc(new_length);
	if (new_content == NULL)
		return (ERROR);
	i = 0;
	while (i < original_length)
	{
		new_content[i] = buffer->content[i];
		i++;
	}
	free(buffer->content);
	buffer->content = new_content;
	buffer->max_length = new_length;
	return (SUCCESS);
}

int	free_buffer(t_buffer *buffer)
{
	free(buffer->content);
	free(buffer);
	return (SUCCESS);
}

int	add_character_to_buffer(t_buffer *buffer, char character)
{
	if (buffer->current_length + 1 > buffer->max_length)
	{
		if (realloc_buffer_content(\
				buffer, \
				buffer->max_length, \
				buffer->max_length * 2) == ERROR)
			return (ERROR);
	}
	buffer->content[buffer->current_length++] = character;
	return (SUCCESS);
}

int	print_buffer(t_buffer *buffer)
{
	write(1, buffer->content, buffer->current_length);
	return (SUCCESS);
}
