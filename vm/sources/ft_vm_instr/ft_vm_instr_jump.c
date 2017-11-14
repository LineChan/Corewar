/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_jump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 01:24:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/14 16:30:30 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO : presentation

#include "ft_vm.h"
#define BYTECODE_GET(bc, pos)	(((bc) >> (8 - ((pos) << 1))) & 0x3)

extern uint8_t	g_direct_jump_table_from_instr[17];


int				ft_vm_instr_jump(t_dead_pool *dead_pool)
{
	int		i;

	i = 0;
	ft_printf("\t{bblack:ft_vm_instr_jump} {green:in}\n\t  -->  ");
	while (i < dead_pool->champ[dead_pool->idx]->instr.op->nb_args)
	{
		if (BYTECODE_GET(dead_pool->champ[dead_pool->idx]->instr.bytecode, i + 1) == IND_CODE)
		{
			DEBUG_MODE ? ft_fprintf(2, "[T_IND]  ") : 0;
			dead_pool->champ[dead_pool->idx]->instr.arg_jump[i] = 2;
			dead_pool->champ[dead_pool->idx]->instr.op->arg_types[i] = T_IND;
		}
		else if (BYTECODE_GET(dead_pool->champ[dead_pool->idx]->instr.bytecode, i + 1) == REG_CODE)
		{
			DEBUG_MODE ? ft_fprintf(2, "[T_REG]  ") : 0;
			dead_pool->champ[dead_pool->idx]->instr.arg_jump[i] = 1;
			dead_pool->champ[dead_pool->idx]->instr.op->arg_types[i] = T_REG;
		}
		else if (BYTECODE_GET(dead_pool->champ[dead_pool->idx]->instr.bytecode, i + 1) == DIR_CODE)
		{
			DEBUG_MODE ? ft_fprintf(2, "[T_DIR]  ") : 0;
			dead_pool->champ[dead_pool->idx]->instr.arg_jump[i] = g_direct_jump_table_from_instr[dead_pool->champ[dead_pool->idx]->instr.op->numero];
			dead_pool->champ[dead_pool->idx]->instr.op->arg_types[i] = T_DIR;
		}
		else
		{
			ft_printf("\n\t{bblack:ft_vm_instr_jump} {red:out}\n");
			return (EXIT_FAILURE);
		}
		++i;
	}
	ft_printf("\n\t{bblack:ft_vm_instr_jump} {green:out}\n");
	return (EXIT_SUCCESS);
	#if 0
	int		i;

	i = 0;
	ft_printf("\t{bblack:ft_vm_instr_jump} {green:in}\n\t  -->  ");
	while (i < dead_pool->i_champ->instr.op->nb_args)
	{
		if (BYTECODE_GET(dead_pool->i_champ->instr.bytecode, i + 1) == IND_CODE)
		{
			DEBUG_MODE ? ft_fprintf(2, "[T_IND]  ") : 0;
			dead_pool->i_champ->instr.arg_jump[i] = 2;
			dead_pool->i_champ->instr.op->arg_types[i] = T_IND;
		}
		else if (BYTECODE_GET(dead_pool->i_champ->instr.bytecode, i + 1) == REG_CODE)
		{
			DEBUG_MODE ? ft_fprintf(2, "[T_REG]  ") : 0;
			dead_pool->i_champ->instr.arg_jump[i] = 1;
			dead_pool->i_champ->instr.op->arg_types[i] = T_REG;
		}
		else if (BYTECODE_GET(dead_pool->i_champ->instr.bytecode, i + 1) == DIR_CODE)
		{
			DEBUG_MODE ? ft_fprintf(2, "[T_DIR]  ") : 0;
			dead_pool->i_champ->instr.arg_jump[i] = g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero];
			dead_pool->i_champ->instr.op->arg_types[i] = T_DIR;
		}
		else
		{
			ft_printf("\n\t{bblack:ft_vm_instr_jump} {red:out}\n");
			return (EXIT_FAILURE);
		}
		++i;
	}
	ft_printf("\n\t{bblack:ft_vm_instr_jump} {green:out}\n");
	return (EXIT_SUCCESS);
	#endif
}
