/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion_specifier.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:54:19 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/18 19:47:55 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	parse_conversion_specifier(
	const char *formatted_string,
	int *i,
	t_conversion_specification *specs
){
	char	current_character;

	current_character = formatted_string[(*i)];
	if (ft_strchr(CONVERSION_SPECIFIERS, current_character) == NULL)
		return (ERROR);
	else
		specs->conversion_specifier = current_character;
	return (SUCCESS);
}
