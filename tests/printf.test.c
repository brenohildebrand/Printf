/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:21:02 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/13 17:40:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

int ft_printf(const char *formatted_string, ...);

int	main(void)
{	
	int	printf_return;
	int	ft_printf_return;

	// freopen("./tests/printf.output", "w", stdout);
	// printf("%c", '0');
	// freopen("./tests/ft_printf.output", "w", stdout);
	// ft_printf("%c", '0');
	// freopen ("/dev/tty", "a", stdout);

	printf("[PRINTF] ");
	fflush(stdout);
	printf_return = printf(" %d ", -1);
	printf("\n");
	printf("[PRINTF] %i\n", printf_return);
	printf("[FT_PRINTF] ");
	fflush(stdout);
	ft_printf_return = ft_printf(" %d ", -1); 
	printf("\n");
	printf("[FT_PRINTF] %i\n", ft_printf_return);

	return (0);
}