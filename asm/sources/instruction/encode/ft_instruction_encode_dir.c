/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_encode_dir.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/13 15:49:05 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "ft_string.h"
#include "endian.h"

int8_t	ft_instruction_encode_dir(t_instr *st, int index, char const *data)
{
	int 	n;

	st->args[index].type = T_DIR;
	st->args[index].size = 2;
	if (LABEL_CHAR == data[1])
	{
		if (0 == st->op->has_index)
			st->args[index].size += 2;
		st->args[index].type |= T_LAB;
		ft_strcpy(st->args[index].data, data + 2);
		return (DIR_CODE);
	}
	n = ft_instruction_encode_get_number(data + 1);
	if (0 == st->op->has_index)
	{
		st->args[index].size += 2;
		*(int32_t *)st->args[index].data = ft_endian_convert_int32((int32_t)n);
	}
	else
		*(int16_t *)st->args[index].data = ft_endian_convert_int16((int16_t)n);
	return (DIR_CODE);
}
