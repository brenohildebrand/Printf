/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_string_to_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:34:00 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/12 23:53:53 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

int	add_string_to_buffer(t_buffer *buffer, char *string)
{
	while (*string)
	{
		if (add_character_to_buffer(buffer, *string) == ERROR)
			return (ERROR);
		string++;
	}
	return (SUCCESS);
}
