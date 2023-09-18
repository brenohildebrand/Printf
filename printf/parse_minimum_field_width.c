/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_minimum_field_width.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:55:17 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/18 19:47:32 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	parse_minimum_field_width(
	const char *formatted_string,
	int *i,
	t_conversion_specification *specs
){
	char	current_character;

	specs->minimum_field_width = 0;
	current_character = formatted_string[(*i)];
	if (ft_isdigit(current_character) && current_character != '0')
	{
		while (ft_isdigit(current_character))
		{
			specs->minimum_field_width *= 10;
			specs->minimum_field_width += (int)(current_character - '0');
			current_character = formatted_string[++(*i)];
		}
	}
	return (SUCCESS);
}
