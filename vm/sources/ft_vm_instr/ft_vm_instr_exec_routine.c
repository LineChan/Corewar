/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_exec_routine.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:44:59 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/15 16:03:04 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : presentation
//TODO : libc.h
#include <libc.h>

void 			ft_vm_instr_exec_routine(unsigned char arena[],
										t_dead_pool *dead_pool)
{
	(void)arena;
	(void)dead_pool;
	if (DEBUG_MODE)
		ft_printf("\n{bblack:ft_vm_instr_exec_routine} {green:in}\n");
	if (ft_vm_instr_decode(dead_pool) == EXIT_SUCCESS)
	{
		ft_vm_instr_exec(arena, dead_pool);
	}
	else
	{
		++dead_pool->champ[CHAMP_IDX].pc;
		++dead_pool->champ[CHAMP_IDX].next_cycle;
	}
	if (DEBUG_MODE)
		ft_printf("\n{bblack:ft_vm_instr_exec_routine} {green:out}\n");
}
