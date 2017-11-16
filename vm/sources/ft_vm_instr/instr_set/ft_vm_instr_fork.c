/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:26:03 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/16 16:28:28 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
// TODO : presentation


// TODO : presentation
void			ft_vm_instr_fork(unsigned char arena[], t_dead_pool *dead_pool)
{
	extern uint8_t g_direct_jump_table_from_instr[17];

	DEBUG_MODE ? ft_printf("{yellow:sti}\n") : 0;
	/* Create a new process and link it to the champion's structure */
	ft_vm_instr_new_process(dead_pool);
	/* Set up the new pointer */
	C_PROCESS(dead_pool->i_champ->process_head.prev)->process.pc =
		&arena[MOD(dead_pool->i_champ->pc - arena + 1 +
		(ft_instruction_get_data(g_direct_jump_table_from_instr[
		dead_pool->i_champ->instr.op->numero], dead_pool->i_champ->pc + 1) % IDX_MOD))];
	/* Move the Program Counter */
	dead_pool->i_champ->pc += g _direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero];
	/* Waiting time until the next instruction */
	dead_pool->i_champ->instr.op->nb_cycles += dead_pool->i_champ->instr.op->nb_cycles;
}
