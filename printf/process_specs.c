/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_specs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 04:10:15 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/15 14:38:15 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	process_specs(
	va_list *args,
	t_conversion_specification *specs,
	t_buffer *conversion_buffer
){
	// outra tentativa
	// a gente soh quer o nosso valor
	if (process_conversion_specifier(specs, args, conversion_buffer) == ERROR)
		return (ERROR);
	// quer saber se vai ter sinal ou nao
	if (process_signal(specs, conversion_buffer) == ERROR)
		return (ERROR);
	// quer saber se eh pra preencher de 0 antes dele ou nao
	if (process_zeros(specs, conversion_buffer) == ERROR)
		return (ERROR);
	// e quer saber se eh pra por espaco ou nao
	if (process_spaces(specs, conversion_buffer) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
