/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_round_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:51:33 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/30 17:55:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

//TODO : libs
#include "ft_printf.h"
#include <libc.h>

void			ft_vm_arena_round_check(t_vm *vm,
										unsigned int *cycle_end_round,
										unsigned int *cycle_to_die)
{
	t_list				*it;
	unsigned int		live_total;

	it = vm->process_head.next;
	live_total = 0;

	if (LOG_OPT)
	{
		ft_log("# ---------------- ROUND CHECK ---------------------\n");
		ft_log("  Cycle %-7d\n", vm->current_cycle);
	}
	while (it != &vm->process_head)
	{
		if (!C_PROCESS(it)->live)
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
			live_total += C_PROCESS(it)->live;
			C_PROCESS(it)->live ^= C_PROCESS(it)->live;
		}
		it = it->next;
		//TODO: MAX_CHECK
	}
	if (live_total >= NBR_LIVE)
		*cycle_to_die -= CYCLE_DELTA;
	if (LOG_OPT)
	{
		ft_log("\t\tTotal lives : %d\n", live_total);
		ft_log("\t\tCycle to die : %d\n", *cycle_to_die);

	}
	DISPLAY_2 ? ft_printf("Cycle to die is now %d\n", *cycle_to_die) : 0;
	*cycle_end_round += *cycle_to_die;
	live_total ^= live_total;
	if (LOG_OPT)
		ft_log("# --------------------------------------------------\n");
}
