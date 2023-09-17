/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_zeros.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:38:21 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/17 01:03:53 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	count_number_of_digits(t_conversion_specification *specs, t_buffer *conversion_buffer, int *number_of_digits)
{
	int	i;

	i = 0;
	*number_of_digits = 0;	
	while (i < conversion_buffer->current_length)
	{
		if (specs->conversion_specifier == 'x' || specs->conversion_specifier == 'X')
			(*number_of_digits)++;
		else if (ft_isdigit(conversion_buffer->content[i]))
			(*number_of_digits)++;
		i++;
	}
	return (SUCCESS);
}

static int	count_number_of_characters(t_buffer *conversion_buffer, int *number_of_characters)
{
	int	i;

	i = 0;
	*number_of_characters = 0;
	while (i < conversion_buffer->current_length)
	{
		(*number_of_characters)++;
		i++;
	}
	return (SUCCESS);
}

static int	add_zeros_to_buffer(t_buffer *conversion_buffer, int number_of_zeros)
{
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
	if (conversion_buffer->current_length > 0 && (conversion_buffer->content[i] == '-' || conversion_buffer->content[i] == '+'))
		new_content[j++] = conversion_buffer->content[i++];
	while (number_of_zeros--)
		new_content[j++] = '0';
	while (i < conversion_buffer->current_length)
		new_content[j++] = conversion_buffer->content[i++];
	free(conversion_buffer->content);
	conversion_buffer->content = new_content;
	// printf("current_length: %lu\n", conversion_buffer->current_length);
	conversion_buffer->current_length = new_length;
	// printf("current_length: %lu\n", conversion_buffer->current_length);

	return (SUCCESS);
}

int	process_zeros(t_conversion_specification *specs, t_buffer *conversion_buffer)
{
	int	number_of_digits;
	int	number_of_characters;

	if (
		specs->conversion_specifier == 'c' ||
		specs->conversion_specifier == 's' ||
		specs->conversion_specifier == 'p'
	)
		return (SUCCESS);
	if (specs->precision >= 0)
	{
		if (count_number_of_digits(specs, conversion_buffer, &number_of_digits) == ERROR)
			return (ERROR);
		// printf("specs->precision: %i\n", specs->precision);
		// printf("number_of_digits: %i\n", number_of_digits);
		// printf("specs->precision - number_of_digits: %i\n", specs->precision - number_of_digits);
		if (add_zeros_to_buffer(conversion_buffer, specs->precision - number_of_digits) == ERROR)
			return (ERROR);
	}
	else if (ZERO_IS_ON(specs->flags) && !DASH_IS_ON(specs->flags))
	{
		if (count_number_of_characters(conversion_buffer, &number_of_characters) == ERROR)
			return (ERROR);
		if (add_zeros_to_buffer(conversion_buffer, specs->minimum_field_width - number_of_characters) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}