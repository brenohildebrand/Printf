/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_specs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 04:10:15 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/14 23:48:02 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	process_specs(
	va_list *args,
	t_conversion_specification *specs,
	t_buffer *conversion_buffer
){
	if (process_conversion_specifier(specs, args, conversion_buffer) == ERROR)
		return (ERROR);
	// if (process_precision(specs, conversion_buffer) == ERROR)
	// 	return (ERROR);
	// if (process_hash_flag(specs, conversion_buffer) == ERROR)
	// 	return (ERROR);
	// if (process_space_flag(specs, conversion_buffer) == ERROR)
	// 	return (ERROR);
	// if (process_sign_flag(specs, conversion_buffer) == ERROR)
	// 	return (ERROR);
	// if (process_minimum_field_width(specs, conversion_buffer) == ERROR)
	// 	return (ERROR);
	return (SUCCESS);
}
