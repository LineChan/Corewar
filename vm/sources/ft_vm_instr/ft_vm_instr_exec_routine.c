/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_exec_routine.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:44:59 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/18 23:16:21 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : presentation
//TODO : libc.h
#include <libc.h>
#include "ft_log.h"

void 			ft_vm_instr_exec_routine(unsigned char arena[],
										t_dead_pool *dead_pool,
										int option[])
{
	if (DEBUG_MODE)
		ft_printf("\n{bblack:ft_vm_instr_exec_routine} {green:in} : %s\n", dead_pool->champ[CHAMP_IDX].header.prog_name);
	/* Execute the instruction if the bytecode is right */
	if (ft_vm_instr_decode(dead_pool) == EXIT_SUCCESS)
		ft_vm_instr_exec(arena, dead_pool, option);
	else
	{
		dead_pool->champ[CHAMP_IDX].pc += 1;
		dead_pool->champ[CHAMP_IDX].next_cycle += 1;
	}
	if (DEBUG_MODE)
		ft_printf("\n{bblack:ft_vm_instr_exec_routine} {green:out}\n");
}
