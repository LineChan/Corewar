/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_lld.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:20:54 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/20 14:43:20 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : presentation


void			ft_vm_instr_lld(unsigned char arena[],
								t_dead_pool *dead_pool,
								int option[])
{
	unsigned int		address;
	unsigned char		*ptr;
	extern uint8_t g_direct_jump_table_from_instr[17];

	/* Set up a pointer at the beginning of the arguments */
	ptr = dead_pool->i_champ->pc + 2;
	/* Read arguments */
	if (dead_pool->i_champ->instr.op->arg_types[0] == T_DIR)
	{
		address = MOD(ft_instruction_get_data(
		g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero],
		ptr));
	}
	else
		address = MOD((dead_pool->i_champ->pc - arena)
									+ ft_instruction_get_data(2, ptr));
	ptr += dead_pool->i_champ->instr.arg_jump[0];
	if (!IS_REG(*ptr))
	{
		ft_vm_instr_fail(dead_pool, CARRY_CHANGE);
		return ;
	}
	/* Load a value in a register */
	dead_pool->i_champ->reg[*ptr] = arena[address];
	/* Move the Program Counter */
	dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0] + dead_pool->i_champ->instr.arg_jump[1];
	/* Write in the logfile */
	OPTION_LOG ? ft_vm_log_lld(dead_pool, ptr, address) : 0;
	/* Waiting time until the next cycle */
	dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
	/* Change the carry */
	dead_pool->i_champ->carry = 0;
}
