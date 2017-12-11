/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_round_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:51:33 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/11 01:18:46 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"
#include "ft_printf.h"

//TODO:libs
#include <libc.h>

void			ft_vm_arena_round_check(t_vm *vm,
										int *cycle_end_round)
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
		if (!C_PROCESS(it)->live)
		{
			/* Delete the process if it did not call the live instruction */
			LOG_OPT ? ft_log("\t\tProcess %d is dead\n",
								-C_PROCESS(it)->process_nb) : 0 ;
			ft_vm_close_process(it);
			--vm->nb_champion;
		}
		it = it->next;
	}
	if ((vm->total_live >= NBR_LIVE) || (check >= MAX_CHECKS))
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		DISPLAY_2 ? ft_printf("Cycle to die is now %d\n", vm->cycle_to_die) : 0;
		check = 0;
	}
	else
		++check;
	if (LOG_OPT)
	{
		ft_log("\t\tTotal lives : %d\n", vm->total_live);
		ft_log("\t\tCycle to die : %d\n", vm->cycle_to_die);
	}
	*cycle_end_round += vm->cycle_to_die;
	vm->total_live = 0;
	if (LOG_OPT)
		ft_log("# --------------------------------------------------\n");
}
