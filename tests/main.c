/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:21:45 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/09 14:17:23 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

#include <stdio.h>

// fflush is needed because printf seems to only flush when it encounters a '\n'
int	main(void)
{
	printf("[printf] - ");
	printf("hello world");
	printf("\n");

	printf("[ft_printf] - ");
	fflush(stdout);
	ft_printf("hello world");
	printf("\n");

	return (0);
}