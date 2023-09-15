/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:50:16 by bhildebr          #+#    #+#             */
/*   Updated: 2023/09/15 11:39:25 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	convert_i(
	va_list *args,
	t_buffer *conversion_buffer
){
	int		arg;
	char	*cstring;

	arg = va_arg(*args, int);
	
	// convert specifier
	cstring = ft_int_itoa_base(arg, DEC_BASE);
	if (cstring == NULL)
		return (ERROR);

	// value and precision
	if (precision <= ft_strlen(cstring))
	{
		append_cstring_to_buffer(conversion_buffer, cstring);
	}
	else
	{
		append_cstring_to_buffer(conversion_buffer, cstring);
		int nzeros = ft_strlen(cstring) - precision;
		while (nzeros--)
		{
			prepend_character_to_buffer(conversion_buffer, '0');
		}
	}

	// alternate form (does not apply)
	

	if (add_cstring_to_buffer(conversion_buffer, cstring) == ERROR)
		return (ERROR);
	free(cstring);

	// value -> precision (only change the value) -> alternate form -> padding (consider the side) -> signal -> margin (padding is between the signal and the margin)

	// numeric value
	// precision (expand if precision is less than number size)
	// alternate form
	// padding

	// pega o valor
	// verifica se precisa preencher com zeros a esqueda devido a precisao
	// verifica se tem uma forma alternativa baseado na flag de forma alternativa
	// verifica se eh pra colocar sinal com a flag de sinal
	// 

	//	define se vai fazer padding (minimum_field_width > buffer->current_size)
	//	define o lado que o padding vai acontecer (esquerda ou direita)
	//		se a flag dash tiver definida vai ser na direita
	//		se nao vai ser na esquerda
	//	define o que vai ser usado pro padding (' ' ou 0)
	//		se zero ja tiver sido usado na precisao ou se o padding for na direita usa espaco obrigatoriamente
	//		senao checa pra ver se tem 0 nas flags e se tiver usa o zero
	//		senao usa espaco mesmo
	//	se preencher com zero, considere que o zero faz parte do numero e poe o sinal/espaco antes
	//	se preencher com espaco o numero era aquele mesmo

	// outra tentativa
	// a gente soh quer o nosso valor
	// quer saber se vai ter sinal ou nao
	// quer saber se eh pra preencher de 0 antes dele ou nao
	// e quer saber se eh pra por espaco ou nao
	
	return (SUCCESS);
}
