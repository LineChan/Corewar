/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_ld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:49:07 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/19 00:32:40 by mvillemi         ###   ########.fr       */
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
#include "ft_log.h"

void			ft_vm_instr_ld(unsigned char arena[],
								t_dead_pool *dead_pool,
								int option[])
{
	unsigned int		address;
	unsigned char		*ptr;
	extern				uint8_t g_direct_jump_table_from_instr[17];

	ft_printf("{yellow:ld}\n");
	/* Set a pointer at the beginning of the arguments */
	ptr = dead_pool->i_champ->pc + 2;
	/* Read arguments */
	if (dead_pool->i_champ->instr.op->arg_types[0] == T_DIR)
	{
		address = MOD(ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero], ptr));
	}
	else
	{
		address = MOD(dead_pool->i_champ->pc - arena + ft_instruction_get_data(2, ptr) % IDX_MOD);
	}
	ptr += dead_pool->i_champ->instr.arg_jump[0];
	/* Load the value in a register */
	// NB : IS_REG(*(pc + 2 + dead_pool->i_champ->instr.arg_jump[0]))
	if (IS_REG(*ptr))
	{
		//dead_pool->i_champ->reg[*ptr] = value_to_load;
		dead_pool->i_champ->reg[*ptr] = arena[address];
		/* Move the Program Counter */
		dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0]
										+ dead_pool->i_champ->instr.arg_jump[1];
		/* Change the carry */
		dead_pool->i_champ->carry = 0;
		OPTION_LOG ? ft_vm_log_ld(dead_pool, ptr) : 0;
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
