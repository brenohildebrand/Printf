/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:26:04 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/13 14:56:09 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>

# ifndef SUCCESS
#  define SUCCESS 0
# endif

# ifndef ERROR
#  define ERROR -1
# endif

typedef struct s_string {
    char    *content;
    size_t  size;
}   t_string;

int	malloc_string(t_string **string_address);

#endif