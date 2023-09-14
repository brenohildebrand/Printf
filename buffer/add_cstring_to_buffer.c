/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cstring_to_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:34:00 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/14 05:16:05 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

int	add_cstring_to_buffer(t_buffer *buffer, char *cstring)
{
	while (*cstring)
	{
		if (add_character_to_buffer(buffer, *cstring) == ERROR)
			return (ERROR);
		cstring++;
	}
	return (SUCCESS);
}
