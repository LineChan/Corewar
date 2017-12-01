/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_round_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:51:33 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/01 18:00:39 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"
#include "ft_printf.h"

void			ft_vm_arena_round_check(t_vm *vm,
										unsigned int *cycle_end_round,
										int *cycle_to_die)
{
	t_list				*it;
	static int			check = 0;

	it = vm->process_head.next;

	if (LOG_OPT)
	{
		ft_log("# ---------------- ROUND CHECK ---------------------\n");
		ft_log("  Cycle %-7d\n", vm->current_cycle);
	}
	while (it != &vm->process_head)
	{
		if (!C_PROCESS(it)->live[0])
		{
			/* Delete the process if it did not call the live instruction */
			LOG_OPT ?
				ft_log("\t\tProcess %d is dead\n", -C_PROCESS(it)->process_nb) : 0 ;
			ft_vm_close_process(it);
			--vm->nb_champion;
		}
		else
		{
			/* Count the number of live done and set it up for the next round */
			vm->total_live += C_PROCESS(it)->live[0];
			C_PROCESS(it)->live[0] ^= C_PROCESS(it)->live[0];
		}
		it = it->next;
	}
	if ((vm->total_live >= NBR_LIVE) || (check >= MAX_CHECKS))
	{
		*cycle_to_die -= CYCLE_DELTA;
		DISPLAY_2 ? ft_log("OUTPUT CYCLE TO DIE\n") : 0;
		DISPLAY_2 ? ft_printf("Cycle to die is now %d\n", *cycle_to_die) : 0;
		check ^= check;
	}
	else
		++check;
	if (LOG_OPT)
	{
		ft_log("\t\tTotal lives : %d\n", vm->total_live);
		ft_log("\t\tCycle to die : %d\n", *cycle_to_die);

	}
	*cycle_end_round += *cycle_to_die;
	vm->total_live ^= vm->total_live;
	if (LOG_OPT)
		ft_log("# --------------------------------------------------\n");
}
