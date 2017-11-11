/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_zjmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:39:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/10 23:11:24 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : Presentation
// TODO : carry
// TODO : remove libc

extern uint8_t g_direct_jump_table_from_instr[17];

void			ft_vm_instr_zjmp(unsigned char arena[], t_dead_pool *dead_pool)
{
	(void)arena;
	dead_pool->i_champ->pc +=
	MOD(ft_instruction_get_data(
		g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero],
		dead_pool->i_champ->pc + 1) % IDX_MOD);
}
