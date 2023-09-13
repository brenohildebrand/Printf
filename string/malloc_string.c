/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:28:14 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/13 14:56:16 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	malloc_string(t_string **string_address)
{
	(*string_address) = malloc(sizeof(t_string));
	if ((*string_address) == NULL)
		return (ERROR);
	(*string_address)->content = malloc(1 * sizeof(char));
	if ((*string_address)->content == NULL)
	{
		free((*string_address));
		return (ERROR);
	}
	return (SUCCESS);
}