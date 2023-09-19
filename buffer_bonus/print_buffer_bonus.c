/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buffer_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:34:10 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/19 17:13:24 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_bonus.h"

int	print_buffer(t_buffer *buffer)
{
	write(1, buffer->content, buffer->current_length);
	return (SUCCESS);
}
