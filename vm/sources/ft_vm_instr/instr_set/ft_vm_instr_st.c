/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_st.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 20:32:54 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/19 16:30:49 by mvillemi         ###   ########.fr       */
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
			ft_vm_instr_fail(dead_pool, !CARRY_CHANGE);
			return ;
		}
		/* Store the value in a register */
		dead_pool->i_champ->reg[*(dead_pool->i_champ->pc + 3)] = dead_pool->i_champ->reg[*(dead_pool->i_champ->pc + 2)];
		/* Write in the logfile */
		(OPTION_LOG) ? ft_vm_log_st(dead_pool, arena, T_REG) : 0;
	}
	else
	{
		if (!IS_REG(*(dead_pool->i_champ->pc + 2)))
		{
			ft_vm_instr_fail(dead_pool, !CARRY_CHANGE);
			return ;
		}
		/* Store a value in a directory */
		arena[MOD((dead_pool->i_champ->pc - arena) + (ft_instruction_get_data(2, dead_pool->i_champ->pc + 3) % IDX_MOD))] = dead_pool->i_champ->reg[*(dead_pool->i_champ->pc + 2)];
		/* Write in the logfile */
		(OPTION_LOG) ? ft_vm_log_st(dead_pool, arena, T_IND) : 0;
	}
	/* Move the Program Counter */
	dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0] + dead_pool->i_champ->instr.arg_jump[1];
	/* Waiting time until the next instruction */
	dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
}
