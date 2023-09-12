/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:21:02 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/12 16:21:30 by bhildebr         ###   ########.fr       */
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