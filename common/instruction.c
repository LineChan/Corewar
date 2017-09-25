/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/25 08:35:35 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "endian.h"
#include <stdlib.h>
#include <stdio.h>

#define SET_TYPE(x)		((1 == (x)) ? T_REG : (2 == (x)) ? T_DIR : T_IND)

static int const	g_bytecode_type[4] =
{
	0, T_REG, T_DIR, T_IND
};

static int const	g_bytecode_size[17] =
{
	-1, 4, 4, 0, 0, 0, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 0
};

static void	ft_instruction_set_arg_pos(t_instr_args *arg, uint8_t **pc, int num, int bc)
{
	int	size;

	arg->type = g_bytecode_type[(bc >> 6) ^ 0x3];
	printf("   +--> Type: %s\n", arg->type == 1 ? "T_REG" : arg->type == 2 ? "T_DIR" : "T_IND");
	if (T_REG == arg->type)
		arg->data[3] = *(*pc)++;
	else if (T_IND == arg->type)
	{
		ECu16_ASSIGN(arg->data + 2, *pc);
		(*pc) += 2;
	}
	else if (0 != (size = g_bytecode_size[num]))
	{
		if (2 == size)
			ECu16_ASSIGN(arg->data + 2, *pc);
		else
			ECu32_ASSIGN(arg->data, *pc);
		(*pc) += size;
	}
}

static void	ft_instruction_set_args(t_instr *st, uint8_t *idx)
{
	extern t_op	g_op_tab[17];
	uint8_t		bytecode;
	uint8_t		*pc;
	size_t		i;

	i = 0;
	pc = idx + 1;
	bytecode = *pc++;
	while (i < 3 && i < st->nb_args)
	{
		printf("%s -> %d\n", g_op_tab[*idx].name, (int)i);
		ft_instruction_set_arg_pos(&st->args[i], &pc, g_bytecode_size[*idx], bytecode);
		bytecode <<= 2;
		++i;
	}
	st->instr_size = (pc - idx);
}

t_instr		*ft_instruction_get(void *pc)
{
	extern t_op	g_op_tab[17];
	t_instr		*st;
	uint8_t		*idx;

	idx = (uint8_t *)pc;
	st = (t_instr *)calloc(1, sizeof(t_instr));
	st->name = g_op_tab[*idx].name;
	st->desc = g_op_tab[*idx].description;
	st->nb_args = g_op_tab[*idx].nb_args;
	st->args = (t_instr_args *)calloc(st->nb_args, sizeof(*st->args));
	if (0 != g_op_tab[*idx].param_byte)
		ft_instruction_set_args(st, idx);
	else
	{
		st->args[0].type = T_DIR;
		/* live (0x01) is the only instruction with no param_byte that is not 3 bytes long, so make it start by 2 */
		if (0x01 == g_op_tab[*idx].numero)
			st->instr_size += 2;
		ECu16_ASSIGN(st->args[0].data + st->instr_size, idx + 1 + st->instr_size);
		st->instr_size += 3;
	}
	return (st);
}

void		ft_instruction_del(t_instr **ptr)
{
	if (0 != *ptr)
	{
		if (0 != (*ptr)->nb_args)
			free((void *)(*ptr)->args);
		free((void *)*ptr);
		*ptr = 0;
	}
}
