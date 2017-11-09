/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_ld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:49:07 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/09 19:02:07 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
// TODO: presentation

extern uint8_t g_direct_jump_table_from_instr[17];
/*
* brief      		Execute ld : Take a random argument and a registry.
* Load the value of the first argument in the registry. It will change the carry.
*
* param arena		Memory dedicated to the virtual machine
* param champ
*/
//TODO : do the carry change

// TODO : remove libc.h
#include <libc.h>

void			ft_vm_instr_ld(unsigned char arena[], t_dead_pool *dead_pool)
{
	unsigned int		value_to_load;
	unsigned char		*ptr;

	ptr = dead_pool->i_champ->pc + 2;
	if (dead_pool->i_champ->instr.op->arg_types[0] == T_DIR)
		value_to_load = arena[MOD(ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero], ptr))];
	else
		value_to_load = arena[MOD((dead_pool->i_champ->pc - arena) + ft_instruction_get_data(2, ptr) % IDX_MOD)];
	ptr += dead_pool->i_champ->instr.arg_jump[0];
	dead_pool->i_champ->reg[*ptr] = value_to_load;
	if (DEBUG_MODE)
	{
		ft_printf("{yellow:ld}\n");
		ft_vm_print_reg(dead_pool->i_champ);
	}
	dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0] + dead_pool->i_champ->instr.arg_jump[1];
	if (DEBUG_MODE)
	{
		getchar();
		ft_vm_print_arena((void *)arena, MEM_SIZE, 64, dead_pool);
	}
}