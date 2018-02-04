/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_encode_ind.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/13 03:17:33 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "ft_string.h"
#include "endian.h"

int8_t	ft_instruction_encode_ind(t_instr *st, int index, char const *data)
{
	int16_t	number;

	st->args[index].type = T_IND;
	st->args[index].size = 2;
	if (LABEL_CHAR == data[0])
	{
		st->args[index].type |= T_LAB;
		ft_strcpy(st->args[index].data, data + 1);
	}
	else
	{
		number = (int16_t)ft_instruction_encode_get_number(data);
		*(int16_t *)st->args[index].data = ft_endian_convert_int16(number);
	}
	return (IND_CODE);
}
