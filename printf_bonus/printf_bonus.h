/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:51:17 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/19 17:30:10 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_BONUS_H
# define PRINTF_BONUS_H

# include "../buffer/buffer.h"
# include "../libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define DEC_BASE "0123456789"
# define HEX_BASE "0123456789ABCDEF"
# define HEX_LOWERCASE_BASE "0123456789abcdef"
# define HEX_UPPERCASE_BASE "0123456789ABCDEF"

# define FLAGS "#0- +"
# define CONVERSION_SPECIFIERS "cspdiuxX%"

typedef struct s_conversion_specification
{
	int		flags;
	int		precision;
	int		minimum_field_width;
	int		length_modifier;
	char	conversion_specifier;
}	t_conversion_specification;

int	add_conversion_specification_to_buffer(
		t_buffer *buffer,
		va_list *args,
		t_conversion_specification *specs
		);
int	convert_c(
		va_list	*args,
		t_buffer *conversion_buffer
		);
int	convert_d(
		va_list *args,
		t_buffer *conversion_buffer
		);
int	convert_i(
		va_list *args,
		t_buffer *conversion_buffer
		);
int	convert_p(
		va_list *args,
		t_buffer *conversion_buffer
		);
int	convert_percentage(
		t_buffer *conversion_buffer
		);
int	convert_s(
		va_list *args,
		t_buffer *conversion_buffer,
		t_conversion_specification *specs
		);
int	convert_u(
		va_list *args,
		t_buffer *conversion_buffer
		);
int	convert_upper_x(
		va_list *args,
		t_buffer *conversion_buffer
		);
int	convert_x(
		va_list *args,
		t_buffer *conversion_buffer
		);
int	parse_conversion_specification(
		const char *formatted_string,
		int *i,
		t_conversion_specification *specs
		);
int	parse_formatted_string(
		const char *formatted_string,
		t_buffer *buffer,
		va_list *args
		);
int	parse_conversion_specifier(
		const char *formatted_string,
		int *i,
		t_conversion_specification *specs
		);
int	parse_flags(
		const char *formatted_string,
		int *i,
		t_conversion_specification *specs
		);
int	parse_minimum_field_width(
		const char *formatted_string,
		int *i,
		t_conversion_specification *specs
		);
int	parse_precision(
		const char *formatted_string,
		int *i,
		t_conversion_specification *specs
		);
int	process_conversion_specifier(
		t_conversion_specification *specs,
		va_list	*args,
		t_buffer *conversion_buffer
		);
int	process_signal(
		t_conversion_specification *specs,
		t_buffer *conversion_buffer
		);
int	process_spaces(
		t_conversion_specification *specs,
		t_buffer *conversion_buffer
		);
int	process_zeros(
		t_conversion_specification *specs,
		t_buffer *conversion_buffer
		);
int	process_specs(
		va_list *args,
		t_conversion_specification *specs,
		t_buffer *conversion_buffer
		);
int	process_alternate_form(
		t_conversion_specification *specs,
		t_buffer *conversion_buffer
		);

#endif