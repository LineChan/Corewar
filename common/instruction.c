/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/27 08:35:33 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "endian.h"
#include <stdlib.h>

static int	ft_instruction_get_data(size_t size, uint8_t *pc)
{
	if (1 == size)
		return (*pc);
	if (2 == size)
		return (ft_endian_convert_int16(*(int16_t *)pc));
	return (ft_endian_convert_int32(*(int32_t *)pc));
}

static int	ft_instruction_set_args(t_instr *st, uint8_t *idx, int pb)
{
	uint8_t	bytecode;
	uint8_t	*pc;
	size_t	i;

	i = 0;
	pc = idx + 1;
	bytecode = *pc;
	pc += pb;
	while (i < st->nb_args)
	{
		st->args[i].type = (0 != pb) ? (bytecode >> 6) & 0x3 : T_DIR;
		if (T_REG == st->args[i].type)
			st->args[i].size = 1;
		else if (T_IND == st->args[i].type)
			st->args[i].size = 2;
		else if (1 == *idx || 2 == *idx || 13 == *idx || (5 < *idx && 9 > *idx))
			st->args[i].size = 4;
		else
			st->args[i].size = 2;
		st->args[i].data = ft_instruction_get_data(st->args[i].size, pc);
		bytecode <<= 2;
		pc += st->args[i].size;
		++i;
	}
	return (pc - idx);
}

t_instr		*ft_instruction_get(void const *pc)
{
	extern t_op	g_op_tab[17];
	t_instr		*st;
	uint8_t		*idx;

	idx = (uint8_t *)pc;
	st = (t_instr *)malloc(sizeof(t_instr));
	st->op = *idx;
	st->name = g_op_tab[*idx].name;
	st->desc = g_op_tab[*idx].description;
	st->nb_cycles = g_op_tab[*idx].nb_cycles;
	st->has_index = g_op_tab[*idx].has_index;
	st->nb_args = g_op_tab[*idx].nb_args;
	st->args = (t_instr_args *)malloc(st->nb_args * sizeof(0[st->args]));
	st->instr_size = ft_instruction_set_args(st, idx, g_op_tab[*idx].param_byte);
	return (st);
}

void		ft_instruction_del(t_instr **ptr)
{
	if (0 != *ptr)
	{
		free((void *)(*ptr)->args);
		free((void *)*ptr);
		*ptr = 0;
	}
}
