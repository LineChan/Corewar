/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_lld.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:20:54 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/10 15:47:11 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : presentation
// TODO : carry
// TODO : remove libc.h
#include <libc.h>

extern uint8_t g_direct_jump_table_from_instr[17];

void			ft_vm_instr_lld(unsigned char arena[], t_dead_pool *dead_pool)
{
	unsigned int		value_to_load;
	unsigned char		*ptr;

	ptr = dead_pool->i_champ->pc + 2;
	if (dead_pool->i_champ->instr.op->arg_types[0] == T_DIR)
	{
		value_to_load =
		arena[MOD(ft_instruction_get_data(
			g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero], ptr))];
	}
	else
		value_to_load = arena[MOD((dead_pool->i_champ->pc - arena) + ft_instruction_get_data(2, ptr))];
	ptr += dead_pool->i_champ->instr.arg_jump[0];
	if (IS_REG(*ptr))
	{
		dead_pool->i_champ->reg[*ptr] = value_to_load;
		dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0] + dead_pool->i_champ->instr.arg_jump[1];
		dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
	}
	else
		dead_pool->i_champ->pc += 1;
	if (DEBUG_MODE)
	{
		ft_printf("{yellow:ld}\n");
		ft_vm_print_reg(dead_pool->i_champ);
	}
}
