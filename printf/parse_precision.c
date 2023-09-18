/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:54:45 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/18 18:57:04 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	parse_precision(
	const char *formatted_string,
	int *i,
	t_conversion_specification *specs
){
	specs->precision = -1;
	if (formatted_string[(*i)] == '.')
	{
		if (formatted_string[++(*i)] == '-')
		{
			while (ft_isdigit(formatted_string[++(*i)]))
				;
			specs->precision = -1;
		}
		else
		{
			specs->precision = 0;
			while (ft_isdigit(formatted_string[(*i)]))
			{
				specs->precision *= 10;
				specs->precision += (int)(formatted_string[(*i)] - '0');
				(*i)++;
			}
		}
	}
	return (SUCCESS);
}
