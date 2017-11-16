/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_lfork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 08:47:26 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/16 09:00:15 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : presentation
extern uint8_t	g_direct_jump_table_from_instr[17];

void		ft_vm_instr_lfork(unsigned char arena[], t_dead_pool *dead_pool)
{
	DEBUG_MODE ? ft_printf("{yellow:sti}\n") : 0;
	/* Create a new process and link it to the champion's structure */
	ft_vm_instr_new_process(dead_pool);
	/* Move the Program Counter */
	C_PROCESS(dead_pool->i_champ->process_head.prev)->process.pc = &arena[MOD(dead_pool->i_champ->pc - arena + ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero], dead_pool->i_champ->pc + 1))];
	/* Set up the new pointer */
	dead_pool->i_champ->pc += 1 + g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero];
}
