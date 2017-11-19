/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_lfork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 08:47:26 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/18 18:49:20 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : presentation

void		ft_vm_instr_lfork(unsigned char arena[],
								t_dead_pool *dead_pool,
								int option[])
{
	extern uint8_t	g_direct_jump_table_from_instr[17];

	DEBUG_MODE ? ft_printf("{yellow:sti}\n") : 0;
	/* Create a new process and link it to the champion's structure */
	ft_vm_instr_new_process(dead_pool);
	/* Move the Program Counter */
	C_PROCESS(dead_pool->i_champ->process_head.prev)->process.pc =
			&arena[MOD(dead_pool->i_champ->pc - arena
			+ ft_instruction_get_data(g_direct_jump_table_from_instr
			[dead_pool->i_champ->instr.op->numero], dead_pool->i_champ->pc + 1))];
	/* Set up the new pointer */
	dead_pool->i_champ->pc += g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero];
	/* Waiting time until the next instruction */
	dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
	if (OPTION_LOG)
		ft_fprintf(OPTION_LOG, "(%d) : lfork at %hhx\n", CHAMP_IDX + 1, *(dead_pool->i_champ->pc + 1));
}
