/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_ld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:49:07 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/17 17:18:52 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
// TODO: presentation

/*
* brief      		Execute ld : Take a random argument and a registry.
* Load the value of the first argument in the registry. It will change the carry.
*
* param arena		Memory dedicated to the virtual machine
* param champ
*/
// TODO : remove libc.h
#include <libc.h>

void			ft_vm_instr_ld(unsigned char arena[],
								t_dead_pool *dead_pool,
								int option[])
{
	// NB : Value to load can be removed (if ... else)
	unsigned int		value_to_load;
	unsigned char		*ptr;
	extern				uint8_t g_direct_jump_table_from_instr[17];

	ft_printf("{yellow:ld}\n");
	/* Set a pointer at the beginning of the arguments */
	ptr = dead_pool->i_champ->pc + 2;
	/* Read arguments */
	if (dead_pool->i_champ->instr.op->arg_types[0] == T_DIR)
	{
		value_to_load = arena[MOD(
			ft_instruction_get_data(g_direct_jump_table_from_instr[
									dead_pool->i_champ->instr.op->numero], ptr))];
	}
	else
	{
		value_to_load = arena[MOD(dead_pool->i_champ->pc - arena +
									ft_instruction_get_data(2, ptr) % IDX_MOD)];
	}
	ptr += dead_pool->i_champ->instr.arg_jump[0];
	/* Load the value in a register */
	// NB : IS_REG(*(pc + 2 + dead_pool->i_champ->instr.arg_jump[0]))
	if (IS_REG(*ptr))
	{
		dead_pool->i_champ->reg[*ptr] = value_to_load;
		/* Move the Program Counter */
		dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0]
										+ dead_pool->i_champ->instr.arg_jump[1];
		/* Change the carry */
		dead_pool->i_champ->carry = 0;
		if (OPTION_SUMMARY)
			ft_fprintf(OPTION_SUMMARY, "(%d) cycle : %d : ld\n\tREG[%hhx] = %d\n",
				CHAMP_IDX + 1, dead_pool->i_champ->next_cycle,
				*ptr, dead_pool->i_champ->reg[*ptr]);
		/* Waiting time until the next instruction */
		dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
	}
	else
	{
		dead_pool->i_champ->pc += 1;
		dead_pool->i_champ->next_cycle += 1;
		dead_pool->i_champ->carry = 1;
	}
	DEBUG_MODE ? ft_vm_print_reg(&dead_pool->champ[CHAMP_IDX]) : 0;
}
