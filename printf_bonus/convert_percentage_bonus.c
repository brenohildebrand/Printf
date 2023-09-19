/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percentage_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:36:48 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/19 17:16:09 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	convert_percentage(
	t_buffer *conversion_buffer
){
	if (add_character_to_buffer(conversion_buffer, '%') == ERROR)
		return (ERROR);
	return (SUCCESS);
}
