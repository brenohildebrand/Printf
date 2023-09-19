/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_itoa_base_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:08:08 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/19 17:13:46 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

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

static size_t	get_string_len(int value, char *base)
{
	int		_value;
	size_t	base_len;
	size_t	string_len;

	base_len = ft_strlen(base);
	string_len = 0;
	if (value < 0)
	{
		string_len += 1;
		_value = -value;
	}
	else
	{
		_value = value;
	}
	while (_value > 0)
	{
		_value /= base_len;
		string_len++;
	}
	return (string_len);
}

static char	*get_string(
	int value,
	char *base,
	char *string,
	size_t string_len
){
	int		_value;
	size_t	base_len;

	base_len = ft_strlen(base);
	string[string_len] = '\0';
	if (value < 0)
	{
		_value = -value;
		string[0] = '-';
		while (string_len-- >= 2)
		{
			string[string_len] = base[_value % base_len];
			_value /= base_len;
		}
	}
	else
	{
		_value = value;
		while (string_len--)
		{
			string[string_len] = base[_value % base_len];
			_value /= base_len;
		}
	}
	return (string);
}

char	*ft_int_itoa_base(int value, char *base)
{
	size_t	string_len;
	char	*string;

	if (value == -2147483648 && ft_strncmp(base, "0123456789", 10) == 0)
		return (ft_strdup("-2147483648"));
	else if (\
		value == -2147483648 && \
		(!ft_strncmp(base, "0123456789abcdef", 16) || \
		!ft_strncmp(base, "0123456789ABCDEF", 16))
	)
		return (ft_strdup("80000000"));
	if (value == 0)
		return (handle_zero(base));
	string_len = get_string_len(value, base);
	string = ft_calloc(string_len + 1, sizeof(char));
	if (string == NULL)
		return (NULL);
	string = get_string(value, base, string, string_len);
	return (string);
}
