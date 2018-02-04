/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_encode_reg.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/13 00:54:17 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "ft_string.h"

int8_t	ft_instruction_encode_reg(t_instr *st, int index, char const *data)
{
	int8_t	number;

	st->args[index].type = T_REG;
	st->args[index].size = 1;
	number = (int8_t)ft_instruction_encode_get_number(data + 1);
	*(int8_t *)st->args[index].data = number;
	return (REG_CODE);
}
