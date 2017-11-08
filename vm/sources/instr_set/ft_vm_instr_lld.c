/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_lld.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:20:54 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/08 12:57:04 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : presentation
// TODO : carry
// TODO : remove libc.h
#include <libc.h>

extern uint8_t g_direct_jump_table_from_instr[17];

void				ft_vm_instr_lld(unsigned char arena[],
									t_dead_pool *dead_pool,
									t_champion *champ)
{
	unsigned int		value_to_load;
	unsigned char		*ptr;

	(void)dead_pool;
	ptr = champ->pc + 2;
	if (champ->instr.op->arg_types[0] == T_DIR)
	{

		value_to_load =
		arena[MOD(ft_instruction_get_data(
			g_direct_jump_table_from_instr[champ->instr.op->numero], ptr))];
	}
	else
		value_to_load = arena[MOD((champ->pc - arena) + ft_instruction_get_data(2, ptr))];
	ptr += champ->instr.arg_jump[0];
	champ->reg[*ptr] = value_to_load;
	if (DEBUG_MODE)
	{
		ft_printf("{yellow:ld}\n");
		ft_vm_print_reg(champ);
	}
	champ->pc += 2 + champ->instr.arg_jump[0] + champ->instr.arg_jump[1];
	if (DEBUG_MODE)
	{
		getchar();
		ft_vm_print_arena((void *)arena, MEM_SIZE, 64, dead_pool);
	}
}
