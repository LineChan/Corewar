/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_zjmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:39:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/17 17:18:17 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : Presentation
// TODO : carry
// TODO : remove libc

extern uint8_t g_direct_jump_table_from_instr[17];

void			ft_vm_instr_zjmp(unsigned char arena[],
									t_dead_pool *dead_pool,
									int option[])
{
	(void)arena;
	if (dead_pool->i_champ->carry)
	{
		dead_pool->i_champ->pc +=
			MOD(ft_instruction_get_data(
				g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero],
				dead_pool->i_champ->pc + 1) % IDX_MOD);
	}
	if (OPTION_SUMMARY)
		ft_fprintf(OPTION_SUMMARY,"(%d) cycle : %d -> zjump\n\tJump of %d\n", CHAMP_IDX + 1,
			dead_pool->i_champ->next_cycle,
			MOD(ft_instruction_get_data(
			g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero],
			dead_pool->i_champ->pc + 1) % IDX_MOD));
	dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
}
