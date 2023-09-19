/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_cstring_to_buffer_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:39:14 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/19 17:13:12 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_bonus.h"

int	append_cstring_to_buffer(t_buffer *buffer, char *cstring)
{
	while (*cstring)
	{
		if (add_character_to_buffer(buffer, *cstring) == ERROR)
			return (ERROR);
		cstring++;
	}
	return (SUCCESS);
}
