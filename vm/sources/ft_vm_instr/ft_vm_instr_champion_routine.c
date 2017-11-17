/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_champion_routine.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:03:23 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/17 15:18:28 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO: presentation
// TODO : libc.h

#include <libc.h>

void			ft_vm_instr_champion_routine(unsigned char arena[],
												t_dead_pool *dead_pool,
												int option[])
{
	t_list		*it;

	DEBUG_MODE ? ft_printf("\n{bblack:ft_vm_instr_champion_routine} {green:in} '%s'\n", dead_pool->champ[CHAMP_IDX].header.prog_name) : 0;
	if (DEBUG_MODE)
	{
	}
	/* Execute the next instruction if its execution cycle */
	/* is lower than the next cycle to die */
	if ((dead_pool->champ[CHAMP_IDX].next_cycle <= dead_pool->current_cycle) &&
		(*dead_pool->champ[CHAMP_IDX].pc))
	{
		ft_vm_instr_exec_routine(arena, dead_pool, option);
	}
	else
	{
		++dead_pool->champ[CHAMP_IDX].pc;
		++dead_pool->champ[CHAMP_IDX].next_cycle;
	}
	/* If it is the last instruction, the Program Counter is reset at */
	/* the beginning */
	if ((dead_pool->champ[CHAMP_IDX].pc - arena - dead_pool->champ[CHAMP_IDX].index) >= CHAMP_MAX_SIZE)
		dead_pool->champ[CHAMP_IDX].pc = &arena[dead_pool->champ[CHAMP_IDX].index];
	// TODO : subprocess
	/* Exit the function if there is no subprocess */
	if (ft_list_is_empty(&dead_pool->i_champ->process_head))
	{
		DEBUG_MODE ? ft_printf("{bblack:ft_vm_instr_champion_routine} {green:out list emtpy}\n") : 0;
		return ;
	}
	it = dead_pool->i_champ->process_head.next;
	/* Loop on the subprocesses' list */
	while (it != &dead_pool->i_champ->process_head)
	{
		if (dead_pool->i_champ->next_cycle <= dead_pool->current_cycle)
		{
			//dead_pool->i_champ = &dead_pool->champ[CHAMP_IDX];
			dead_pool->i_champ = &C_PROCESS(it)->process;
			ft_vm_instr_exec_routine(arena, dead_pool, option);

		}
		it = it->next;
	}
	if (DEBUG_MODE)
		ft_printf("{bblack:ft_vm_instr_champion_routine} {green:out list not empty}\n");
}

























	#if 0
	if (DEBUG_MODE)
		ft_printf("\n{bblack:ft_vm_instr_champion_routine} {green:in}\n");
	if (!dead_pool->champ[CHAMP_IDX].done)
	{
		#if 0
		ft_printf("{red:routine SEGFAULT}\n");
		ft_printf("ft_instr_decode : %d\n", ft_vm_instr_decode(dead_pool));
		ft_printf("pc : %hhx\n", dead_pool->champ[CHAMP_IDX].pc);
		ft_vm_instr_decode(dead_pool);
		ft_vm_instr_exec(arena, dead_pool);
		#endif
		#if 1
		if ((ft_vm_instr_decode(dead_pool) == EXIT_SUCCESS) &&
			(*dead_pool->champ[CHAMP_IDX].pc > 0) && (*dead_pool->champ[CHAMP_IDX].pc <= INSTR_NUMBER))
		{
			ft_vm_instr_exec(arena, dead_pool);
		}
		else
		{
			++dead_pool->champ[CHAMP_IDX].pc;
			++dead_pool->champ[CHAMP_IDX].next_cycle;
		}
		#endif
	}
	else
	{
		++dead_pool->champ[CHAMP_IDX].pc;
		++dead_pool->champ[CHAMP_IDX].next_cycle;
	}
	if ((dead_pool->champ[CHAMP_IDX].pc - arena - dead_pool->champ[CHAMP_IDX].index) == CHAMP_MAX_SIZE)
		dead_pool->champ[CHAMP_IDX].pc = &arena[dead_pool->champ[CHAMP_IDX].index];
	if (DEBUG_MODE)
		ft_printf("{bblack:ft_vm_instr_champion_routine} {green:out}\n");
	ft_vm_print_arena((void *)arena, MEM_SIZE, 64, dead_pool);
	return ;
	#endif
	#if 0
	(void)arena;
	(void)dead_pool;
	(void)current_cycle;
	if (DEBUG_MODE)
		ft_printf("\n{bblack:ft_vm_instr_champion_routine} {green:in}\n");
	if (!dead_pool->i_champ->done)
	{
		if ((ft_vm_instr_decode(dead_pool) == EXIT_SUCCESS) &&
			(*dead_pool->i_champ->pc > 0) && (*dead_pool->i_champ->pc <= INSTR_NUMBER))
			ft_vm_instr_exec(arena, dead_pool);
		else
		{
				++dead_pool->i_champ->pc;
			++dead_pool->i_champ->next_cycle;
		}
	}
	else
	{
		++dead_pool->i_champ->pc;
		++dead_pool->i_champ->next_cycle;
	}
	if ((dead_pool->i_champ->pc - arena - dead_pool->i_champ->index) == CHAMP_MAX_SIZE)
		dead_pool->i_champ->pc = &arena[dead_pool->i_champ->index];
	if (DEBUG_MODE)
		ft_printf("{bblack:ft_vm_instr_champion_routine} {green:out}\n");
	ft_vm_print_arena((void *)arena, MEM_SIZE, 64, dead_pool);
	return ;
	#endif
