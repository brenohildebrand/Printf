/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_conversion_specifier.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:52:18 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/13 22:08:05 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../string/ft_string.h"
#include "printf.h"

#include <stdarg.h>

#define INT						0
#define UNSIGNED_INT			1
#define POINTER_TO_CHAR			2
#define POINTER_TO_VOID			3
#define LONG_LONG_UNSIGNED_INT	4

static int	define_arg_type(int *type, char conversion_specifier)
{
	if (conversion_specifier == 'c')
		(*type) = INT;
	else if (conversion_specifier == 's')
		(*type) = POINTER_TO_CHAR;
	else if (conversion_specifier == 'p')
		(*type) = POINTER_TO_VOID;
	else if (conversion_specifier == 'd')
		(*type) = INT;
	else if (conversion_specifier == 'i')
		(*type) = INT;
	else if (conversion_specifier == 'u')
		(*type) = UNSIGNED_INT;
	else if (conversion_specifier == 'x')
		(*type) = UNSIGNED_INT;
	else if (conversion_specifier == 'X')
		(*type) = UNSIGNED_INT;
	else
		return (ERROR);
	return (SUCCESS);
}

int	convert_arg_to_string(
	int type, 
	va_list *args, 
	t_string **string_address
){
	
}

int	process_conversion_specifier(
	t_conversion_specification *specs,
	va_list	*args,
	t_string **string_address,
){
	int	type;

	if (define_arg_type(&type, specs->conversion_specifier) == ERROR)
		return (ERROR);
	if (convert_arg_to_string(type, args, string_address) == ERROR)
		return (ERROR);
}

#undef INT
#undef UNSIGNED_INT
#undef POINTER_TO_CHAR
#undef POINTER_TO_VOID
#undef LONG_LONG_UNSIGNED_INT