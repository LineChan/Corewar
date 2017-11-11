/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_ld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:49:07 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/10 22:38:54 by mvillemi         ###   ########.fr       */
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

	(void)arena;
	ft_printf("{yellow:ld}\n");
	/* Set a pointer at the beginning of the arguments */
	ptr = dead_pool->i_champ->pc + 2;
	ft_printf("while ld next_cycle ====> {green:in   1} : %d\n", dead_pool->i_champ->next_cycle);
	/* Read arguments */
	if (dead_pool->i_champ->instr.op->arg_types[0] == T_DIR)
	{
		value_to_load = arena[MOD(ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero], ptr))];
		ft_printf("while ld next_cycle ====> {green:in   2} : %d\n", dead_pool->i_champ->next_cycle);
	}
	else
	{
		value_to_load = arena[MOD((dead_pool->i_champ->pc - arena) + ft_instruction_get_data(2, ptr) % IDX_MOD)];
		ft_printf("while ld next_cycle ====> {green:in   2} : %d\n", dead_pool->i_champ->next_cycle);
	}
	ptr += dead_pool->i_champ->instr.arg_jump[0];
	ft_printf("ptr : %d\n", *ptr);
	/* Load the value in a register */
	if (IS_REG(*ptr))
	{
		dead_pool->i_champ->reg[*ptr] = value_to_load;
		dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0] + dead_pool->i_champ->instr.arg_jump[1];
	}
	else
		dead_pool->i_champ->pc += 1;
	DEBUG_MODE ? ft_vm_print_reg(dead_pool->i_champ) : 0;
}
