/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_champion_routine.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:03:23 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/11 15:30:17 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO: presentation
// TODO : libc.h

#include <libc.h>

void				ft_vm_instr_champion_routine(unsigned char arena[],
												t_dead_pool * dead_pool,
												unsigned const int current_cycle)
{

	(void)arena;
	(void)dead_pool;
	(void)current_cycle;
	ft_printf("\n{bblack:ft_vm_instr_champion_routine} {green:in}\n");
	if ((dead_pool->i_champ->pc) && !dead_pool->i_champ->done)
	{
		if (DEBUG_MODE)
		{
			ft_printf("\nChampion's name : {yellow:%s}\n", dead_pool->i_champ->header.prog_name);
			ft_printf("next_cycle : %d current : %d\n", dead_pool->i_champ->next_cycle, current_cycle);
		}
		if (ft_vm_instr_decode(dead_pool->i_champ) == EXIT_SUCCESS)
			ft_vm_instr_exec(arena, dead_pool);
		else
			dead_pool->i_champ->pc += 1;
	}
	#if 0
	if ((dead_pool->i_champ->pc) && !dead_pool->i_champ->done)
	{
		if (DEBUG_MODE)
		{
			ft_printf("\nChampion's name : {yellow:%s}\n", dead_pool->i_champ->header.prog_name);
			ft_printf("next_cycle : %d current : %d\n", dead_pool->i_champ->next_cycle, current_cycle);
		}
		if (dead_pool->i_champ->next_cycle <= current_cycle)
		{
			if (ft_vm_instr_decode(dead_pool->i_champ) == EXIT_SUCCESS)
				ft_vm_instr_exec(arena, dead_pool);
			else
				dead_pool->i_champ->pc += 1;
			ft_printf("current : %d, prog_size : %d\n", dead_pool->i_champ->pc - arena - dead_pool->i_champ->index,  dead_pool->i_champ->header.prog_size);
			if ((dead_pool->i_champ->pc - arena - dead_pool->i_champ->index) == dead_pool->i_champ->header.prog_size)
				dead_pool->i_champ->pc -= dead_pool->i_champ->header.prog_size;
		}
		else
			dead_pool->i_champ->done = 1;
	}
	else
		DEBUG_MODE ? ft_printf("{red:no champion}\n") : 0;
	DEBUG_MODE ? ft_printf("{bblack:ft_vm_instr_champion_routine} {green:out}\n") : 0;
	#endif
}
