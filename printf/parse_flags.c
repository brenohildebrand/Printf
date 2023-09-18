/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:56:06 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/18 18:56:56 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	parse_flags(
	const char *formatted_string,
	int *i,
	t_conversion_specification *specs
){
	char	current_character;

	specs->flags = 0;
	while (1)
	{
		current_character = formatted_string[++(*i)];
		if (current_character == FLAGS[0])
			specs->flags |= 1 << 0;
		else if (current_character == FLAGS[1])
			specs->flags |= 1 << 1;
		else if (current_character == FLAGS[2])
			specs->flags |= 1 << 2;
		else if (current_character == FLAGS[3])
			specs->flags |= 1 << 3;
		else if (current_character == FLAGS[4])
			specs->flags |= 1 << 4;
		else
			break ;
	}
	return (SUCCESS);
}
