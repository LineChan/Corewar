/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_and.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 23:29:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/19 16:37:33 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : presentation
//TODO : carry
/*
* brief      		Execute and :Apply an & (bit-to-bit AND) over the first
* two arguments and store the result in a registry, which is the third argument. It will change the carry
*
* param arena		Memory allocated to the Virtual Machine
* param champ
*/

//TODO : remove libc.h
#include <libc.h>

void			ft_vm_instr_and(unsigned char arena[],
								t_dead_pool *dead_pool,
								int option[])
{
	int					i;
	unsigned int		and[2];
	unsigned char		*ptr;
	extern uint8_t		g_direct_jump_table_from_instr[17];

	/* Set up a pointer at the beginning of the arguments */
	ptr = dead_pool->i_champ->pc + 2;
	i = 0;
	/* Read arguments */
	while (i < (dead_pool->i_champ->instr.op->nb_args - 1))
	{
		if (dead_pool->i_champ->instr.op->arg_types[i] == T_REG)
		{
			if (!IS_REG(*ptr))
			{
				dead_pool->i_champ->pc += 1;
				dead_pool->i_champ->next_cycle += 1;
				dead_pool->i_champ->carry = 1;
				return ;
			}
			and[i] = dead_pool->i_champ->reg[*ptr];
		}
		else if (dead_pool->i_champ->instr.op->arg_types[i] == T_IND)
			and[i] = arena[MOD(dead_pool->i_champ->pc - arena + ft_instruction_get_data(2, ptr))];
		else
			and[i] = arena[MOD(ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero], ptr))];
		ptr += dead_pool->i_champ->instr.arg_jump[i];
		++i;
	}
	/* Add argument and store the result in an register */
	if (!IS_REG(*ptr))
	{
		ft_vm_instr_fail(dead_pool, CARRY_CHANGE);
		return ;
	}
	dead_pool->i_champ->reg[*ptr] = and[0] & and[1];
	/* Move the Program Counter */
	dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0] + dead_pool->i_champ->instr.arg_jump[1] + dead_pool->i_champ->instr.arg_jump[2];
	/* Write in the logfile */
	OPTION_LOG ? ft_vm_log_and(dead_pool, ptr, and) : 0;
	/* Waiting time until the next instruction */
	dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
	/* Modify the carry */
	dead_pool->i_champ->carry = 0;
}
