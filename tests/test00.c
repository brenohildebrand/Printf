/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:21:45 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/11 16:58:06 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

#include <stdio.h>

// fflush is needed because printf seems to only flush when it encounters a '\n'
int	main(void)
{
	printf("[printf]\t-\t");
	printf("hello, %s", "breno");
	printf("\n");

	printf("[ft_printf]\t-\t");
	fflush(stdout);
	ft_printf("hello, %s", "breno");
	printf("\n");

	return (0);
}