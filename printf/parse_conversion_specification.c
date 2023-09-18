/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion_specification.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:13:21 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/18 15:12:19 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	parse_flags(
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

static int	parse_minimum_field_width(
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

static int	parse_precision(
	const char *formatted_string,
	int *i,
	t_conversion_specification *specs
){
	char	current_character;

	current_character = formatted_string[(*i)];
	specs->precision = -1;
	if (current_character == '.')
	{
		specs->precision = 0;
		current_character = formatted_string[++(*i)];
		while (ft_isdigit(current_character))
		{
			specs->precision *= 10;
			specs->precision += (int)(current_character - '0');
			current_character = formatted_string[++(*i)];
		}
	}
	return (SUCCESS);
}

static int	parse_conversion_specifier(
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

int	parse_conversion_specification(
	const char *formatted_string,
	int *i,
	t_conversion_specification *specs
){
	char	current_character;

	if (parse_flags(formatted_string, i, specs) == ERROR)
		return (ERROR);
	if (parse_minimum_field_width(formatted_string, i, specs) == ERROR)
		return (ERROR);
	if (parse_precision(formatted_string, i, specs) == ERROR)
		return (ERROR);
	if (parse_conversion_specifier(formatted_string, i, specs) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
