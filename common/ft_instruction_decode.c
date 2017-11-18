/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_decode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/08 00:12:27 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "endian.h"
#include "ft_string.h"
#include "ft_printf.h"

extern uint8_t	g_direct_jump_table_from_instr[17];

static int	ft_instruction_get_data(size_t size, uint8_t *pc)
{
	if (1 == size)
		return (*pc);
	if (2 == size)
	{
		if (IS_BIG_ENDIAN)
			return (*(int16_t *)pc);
		return (ft_endian_convert_int16(*(int16_t *)pc));
	}
	if (IS_BIG_ENDIAN)
		return (*(int32_t *)pc);
	return (ft_endian_convert_int32(*(int32_t *)pc));
}

static uint8_t	*ft_instruction_get_args(t_instr *st, uint8_t *idx, int bc)
{
	int		i;

	i = 0;
	while (i < st->op->nb_args)
	{
		st->args.decode[i].type = (bc >> 6) & 0x3;
		if (T_REG == st->args.decode[i].type)
			st->args.decode[i].size = 1;
		else if (T_DIR == st->args.decode[i].type)
			st->args.decode[i].size = g_direct_jump_table_from_instr[st->op->numero];
		else
			st->args.decode[i].size = 2;
		st->args.decode[i].data = ft_instruction_get_data(st->args.decode[i].size, idx);
		bc <<= 2;
		idx += st->args.decode[i].size;
		++i;
	}
	return (idx);
}

t_instr			*ft_instruction_decode(void const *pc)
{
	extern t_op	g_op_tab[17];
	t_instr		*st;
	uint8_t		*idx;
	uint8_t		*jmp;

	idx = (uint8_t *)pc;
	st = (t_instr *)ft_calloc(1, sizeof(t_instr));
	st->type = INSTR_DECODE;
	st->bytecode = idx[1];
	st->op = &g_op_tab[*idx];
	st->args.decode = (t_instr_decode *)ft_calloc(st->op->nb_args, sizeof(0[st->args.decode]));
	if (0 == st->op->param_byte)
		jmp = ft_instruction_get_args(st, idx + 1, DIR_CODE << 6);
	else
		jmp = ft_instruction_get_args(st, idx + 2, idx[1]);
	st->instr_size = jmp - idx;
	return (st);
}
