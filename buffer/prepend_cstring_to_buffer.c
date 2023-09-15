/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepend_cstring_to_buffer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:38:29 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/15 10:38:53 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

int	prepend_cstring_to_buffer(t_buffer *buffer, char *cstring)
{
	while (*cstring)
	{
		if (add_character_to_buffer(buffer, *cstring) == ERROR)
			return (ERROR);
		cstring++;
	}
	return (SUCCESS);
}
