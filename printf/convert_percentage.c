/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percentage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:36:48 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/16 12:44:50 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	convert_percentage(
	va_list	*args,
	t_buffer *conversion_buffer,
	t_conversion_specification *specs
){
	if (add_character_to_buffer(conversion_buffer, '%') == ERROR)
		return (ERROR);
	return (SUCCESS);
}
