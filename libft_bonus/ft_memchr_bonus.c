/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:10:04 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/19 17:14:25 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*src;
	size_t			character;

	index = 0;
	src = (unsigned char *)(s);
	character = (unsigned char)(c);
	while (index < n)
	{
		if (src[index] == character)
			return (&src[index]);
		index++;
	}
	return ((void *)0);
}
