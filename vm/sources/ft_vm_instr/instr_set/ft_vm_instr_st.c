/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_st.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 20:32:54 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/15 13:35:04 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
	//TODO : presentation
extern uint8_t g_direct_jump_table_from_instr[17];
/*
* brief      		Execute ld : Take a registry and a registry or an indirect
* and store the value of the registry toward a second argument
*
* param arena
* param champ
*/

//TODO : remove libc.h
#include <libc.h>

void			ft_vm_instr_st(unsigned char arena[], t_dead_pool *dead_pool)
{
	/* Read arguments */
	if (dead_pool->i_champ->instr.op->arg_types[1] == T_REG)
	{
		if (!IS_REG(*(dead_pool->i_champ->pc + 3)) || !IS_REG(*(dead_pool->i_champ->pc + 2)))
		{
			dead_pool->i_champ->pc += 1;
			return ;
		}
		/* Store the value in a register */
		dead_pool->i_champ->reg[*(dead_pool->i_champ->pc + 3)] = dead_pool->i_champ->reg[*(dead_pool->i_champ->pc + 2)];
	}
	else
	{
		if (!IS_REG(*(dead_pool->i_champ->pc + 2)))
		{
			dead_pool->i_champ->pc += 1;
			return ;
		}
		/* Store a value in a directory */
		arena[MOD((dead_pool->i_champ->pc - arena) + (ft_instruction_get_data(2, dead_pool->i_champ->pc + 3) % IDX_MOD))] = dead_pool->i_champ->reg[*(dead_pool->i_champ->pc + 2)];
	}
	/* Move the Program Counter */
	dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0] + dead_pool->i_champ->instr.arg_jump[1];

	if (DEBUG_MODE)
	{
		ft_printf("{yellow:st}\n");
		ft_vm_print_reg(&dead_pool->champ[CHAMP_IDX]);
	}
}
