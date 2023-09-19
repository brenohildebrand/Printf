/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_specs_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 04:10:15 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/19 17:16:55 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_bonus.h"

int	process_specs(
	va_list *args,
	t_conversion_specification *specs,
	t_buffer *conversion_buffer
){
	if (process_conversion_specifier(specs, args, conversion_buffer) == ERROR)
		return (ERROR);
	if (process_signal(specs, conversion_buffer) == ERROR)
		return (ERROR);
	if (process_zeros(specs, conversion_buffer) == ERROR)
		return (ERROR);
	if (process_alternate_form(specs, conversion_buffer) == ERROR)
		return (ERROR);
	if (process_spaces(specs, conversion_buffer) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
