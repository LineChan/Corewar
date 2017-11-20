/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_zjmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:39:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/20 15:05:54 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : Presentation

extern uint8_t g_direct_jump_table_from_instr[17];

void			ft_vm_instr_zjmp(unsigned char arena[],
									t_dead_pool *dead_pool,
									int option[])
{
	(void)arena;
	/* Jump to the right address */
	if (dead_pool->i_champ->carry)
	{
		dead_pool->i_champ->pc +=
			MOD(ft_instruction_get_data(
				g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero],
				dead_pool->i_champ->pc + 1) % IDX_MOD);
	}
	/* Write in the logfile */
	OPTION_LOG ? ft_vm_log_zjmp(dead_pool, MOD(ft_instruction_get_data(
		g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero],
		dead_pool->i_champ->pc + 1) % IDX_MOD)) : 0;
	/* Waiting time until the next instruction */
	dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
}
