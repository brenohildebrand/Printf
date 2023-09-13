/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_long_long_int_itoa_base.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:08:08 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/13 17:50:04 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*handle_zero(char *base)
{
	char	*string;

	string = ft_calloc(1 + 1, sizeof(char));
	if (string == NULL)
		return (NULL);
	string[0] = base[0];
	string[1] = '\0';
	return (string);
}

static size_t	get_string_len(unsigned long long int value, char *base)
{
	unsigned long long int	_value;
	size_t					base_len;
	size_t					string_len;

	base_len = ft_strlen(base);
	string_len = 0;
	while (value > 0)
	{
		value /= base_len;
		string_len++;
	}
	return (string_len);
}

static char	*get_string(
	unsigned long long int value,
	char *base,
	char *string, 
	size_t string_len
){
	unsigned long long int	_value;
	size_t					base_len;

	base_len = ft_strlen(base);
	string[string_len] = '\0';
	while (string_len--)
	{
		string[string_len] = base[value % base_len];
		value /= base_len;
	}
	return (string);
}

char	*ft_unsigned_long_long_int_itoa_base(unsigned long long int value, char *base)
{
	unsigned long long int	_value;
	size_t					string_len;
	char					*string;
	
	if (value == 0)
		return (handle_zero(base));
	string_len = get_string_len(value, base);
	string = ft_calloc(string_len + 1, sizeof(char));
	if (string == NULL)
		return (NULL);
	string = get_string(value, base, string, string_len);
	return (string);
}
