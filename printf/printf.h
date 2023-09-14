/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:51:17 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/13 20:28:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../buffer/buffer.h"
# include "../libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdarg.h>

# include <stdio.h> 

# define DEC_BASE "0123456789"
# define HEX_BASE "0123456789ABCDEF"
# define HEX_LOWERCASE_BASE "0123456789abcdef"
# define HEX_UPPERCASE_BASE "0123456789ABCDEF"

# define FLAGS "#0- +"
# define CONVERSION_SPECIFIERS "cspdiuxX%"

# define HASH_IS_ON(flags) ((flags & (1 << 0)) != 0)
# define ZERO_IS_ON(flags) ((flags & (1 << 1)) != 0)
# define DASH_IS_ON(flags) ((flags & (1 << 2)) != 0)
# define SPACE_IS_ON(flags) ((flags & (1 << 3)) != 0)
# define SIGN_IS_ON(flags) ((flags & (1 << 4)) != 0)

typedef struct s_conversion_specification
{
	int		flags;
	int		precision;
	int		minimum_field_width;
	int		length_modifier;
	char	conversion_specifier;
}	t_conversion_specification;

int	add_c_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
);
int	add_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
);
int	add_d_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
);
int	add_i_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
);
int	add_p_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
);
int	add_percentage_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
);
int	add_s_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
);
int	add_u_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
);
int	add_x_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
);
int	add_upper_x_conversion_specification_to_buffer(
	t_buffer *buffer,
	va_list *args,
	t_conversion_specification *specs
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

#endif