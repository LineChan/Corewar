/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_st.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 20:32:54 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/17 17:20:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
	//TODO : presentation
/*
* brief      		Execute ld : Take a registry and a registry or an indirect
* and store the value of the registry toward a second argument
*
* param arena
* param champ
*/

//TODO : remove libc.h
#include <libc.h>

void			ft_vm_instr_st(unsigned char arena[],
								t_dead_pool *dead_pool,
								int option[])
{
	extern uint8_t		g_direct_jump_table_from_instr[17];
	/* Read arguments */
	if (dead_pool->i_champ->instr.op->arg_types[1] == T_REG)
	{
		if (!IS_REG(*(dead_pool->i_champ->pc + 3)) || !IS_REG(*(dead_pool->i_champ->pc + 2)))
		{
			dead_pool->i_champ->pc += 1;
			dead_pool->i_champ->next_cycle += 1;
			return ;
		}
		/* Store the value in a register */
		dead_pool->i_champ->reg[*(dead_pool->i_champ->pc + 3)] = dead_pool->i_champ->reg[*(dead_pool->i_champ->pc + 2)];
		if (OPTION_SUMMARY)
			ft_fprintf(OPTION_SUMMARY, "(%d) : st\n\tREG[%c] at %d\n", *(dead_pool->i_champ->pc + 3), dead_pool->i_champ->reg[*(dead_pool->i_champ->pc + 3)]);
	}
	else
	{
		if (!IS_REG(*(dead_pool->i_champ->pc + 2)))
		{
			dead_pool->i_champ->pc += 1;
			dead_pool->i_champ->next_cycle += 1;
			return ;
		}
		/* Store a value in a directory */
		arena[MOD((dead_pool->i_champ->pc - arena) + (ft_instruction_get_data(2, dead_pool->i_champ->pc + 3) % IDX_MOD))] = dead_pool->i_champ->reg[*(dead_pool->i_champ->pc + 2)];
		if (OPTION_SUMMARY)
			ft_fprintf(OPTION_SUMMARY, "(%d) cycle : %d -> st\n\tarena[%hhx] at %d\n", CHAMP_IDX + 1, dead_pool->i_champ->next_cycle, MOD((dead_pool->i_champ->pc - arena) + (ft_instruction_get_data(2, dead_pool->i_champ->pc + 3) % IDX_MOD)), dead_pool->i_champ->reg[*(dead_pool->i_champ->pc + 3)], arena[MOD((dead_pool->i_champ->pc - arena) + (ft_instruction_get_data(2, dead_pool->i_champ->pc + 3) % IDX_MOD))]);
	}
	/* Move the Program Counter */
	dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0] + dead_pool->i_champ->instr.arg_jump[1];
	/* Waiting time until the next instruction */
	dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
	if (DEBUG_MODE)
	{
		ft_printf("{yellow:st}\n");
		ft_vm_print_reg(&dead_pool->champ[CHAMP_IDX]);
	}
}
