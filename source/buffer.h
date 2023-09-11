/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:15:10 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/11 17:21:34 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include <stdlib.h>
# include <unistd.h>

#define SUCCESS 0
#define ERROR -1

typedef struct s_buffer {
	unsigned long	current_length;
	unsigned long	max_length;
	char	*content;
}	t_buffer;

int	malloc_buffer(t_buffer **buffer_address);
int	realloc_buffer_content(t_buffer *buffer, unsigned long original_length, unsigned long new_length);
int	free_buffer(t_buffer *buffer);
int	add_character_to_buffer(t_buffer *buffer, char character);
int print_buffer(t_buffer *buffer);

#endif