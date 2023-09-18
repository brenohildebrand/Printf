/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_zeros.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:38:21 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/18 19:45:20 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	count_ndigits(
	t_conversion_specification *specs,
	t_buffer *conversion_buffer,
	int *ndigits
){
	int	i;

	i = 0;
	*ndigits = 0;
	while (i < conversion_buffer->current_length)
	{
		if (
			specs->conversion_specifier == 'x' || \
			specs->conversion_specifier == 'X')
			(*ndigits)++;
		else if (ft_isdigit(conversion_buffer->content[i]))
			(*ndigits)++;
		i++;
	}
	return (SUCCESS);
}

static int	count_ncharacters(
	t_buffer *conversion_buffer,
	int *ncharacters
){
	int	i;

	i = 0;
	*ncharacters = 0;
	while (i < conversion_buffer->current_length)
	{
		(*ncharacters)++;
		i++;
	}
	return (SUCCESS);
}

static int	add_zeros_to_buffer(
	t_buffer *conversion_buffer,
	int number_of_zeros
){
	int		i;
	int		j;
	char	*new_content;
	int		new_length;

	if (number_of_zeros <= 0)
		return (SUCCESS);
	new_length = conversion_buffer->current_length + number_of_zeros;
	new_content = malloc(new_length * sizeof(char));
	if (new_content == NULL)
		return (ERROR);
	i = 0;
	j = 0;
	if (conversion_buffer->current_length > 0 && \
		(conversion_buffer->content[i] == '-' || \
			conversion_buffer->content[i] == '+'))
		new_content[j++] = conversion_buffer->content[i++];
	while (number_of_zeros--)
		new_content[j++] = '0';
	while (i < conversion_buffer->current_length)
		new_content[j++] = conversion_buffer->content[i++];
	free(conversion_buffer->content);
	conversion_buffer->content = new_content;
	conversion_buffer->current_length = new_length;
	return (SUCCESS);
}

int	process_zeros(
	t_conversion_specification *specs,
	t_buffer *conversion_buffer
){
	int	n;

	if (specs->conversion_specifier == 'c' || \
		specs->conversion_specifier == 's' || \
		specs->conversion_specifier == 'p')
		return (SUCCESS);
	if (specs->precision >= 0)
	{
		if (count_ndigits(specs, conversion_buffer, &n) == ERROR)
			return (ERROR);
		if (add_zeros_to_buffer(conversion_buffer,
				specs->precision - n) == ERROR)
			return (ERROR);
	}
	else if (((specs->flags & (1 << 1)) != 0) && \
	!((specs->flags & (1 << 2)) != 0))
	{
		if (count_ncharacters(conversion_buffer, &n) == ERROR)
			return (ERROR);
		if (add_zeros_to_buffer(
				conversion_buffer,
				specs->minimum_field_width - n) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
