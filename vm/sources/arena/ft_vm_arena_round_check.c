/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_round_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:51:33 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/06 00:11:38 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"
#include "ft_printf.h"

void			ft_vm_arena_round_check(t_vm *vm,
										int *cycle_end_round)
{
	t_list				*it;
	static int			check = 0;

	it = vm->process_head.next;
	if (LOG_OPT)
	{
		ft_log("# ---------------- ROUND CHECK ---------------------\n");
		ft_log("  Cycle %-7d\n", vm->current_cycle - 1);
	}
	while (it != &vm->process_head)
	{
		//if (!C_PROCESS(it)->live)
		#if 0
		if ((!C_PROCESS(it)->live)
			&& ((int)C_PROCESS(it)->has_lived < (vm->current_cycle - vm->cycle_to_die)))
			#endif
		if (!C_PROCESS(it)->dead
			&& ((int)C_PROCESS(it)->has_lived < (vm->current_cycle - vm->cycle_to_die)))
		{
			/* Delete the process if it did not call the live instruction */
			//ft_printf("proc %d : has lived[%d]< current_c[%d] - ctd[%d]\n", C_PROCESS(it)->process_nb,C_PROCESS(it)->has_lived, vm->current_cycle , vm->cycle_to_die);
			LOG_OPT ? ft_log("\t\tProcess %d is dead\n",
								-C_PROCESS(it)->process_nb) : 0 ;
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					-C_PROCESS(it)->process_nb ,
					vm->current_cycle - 1 - C_PROCESS(it)->has_lived,
					vm->cycle_to_die);
			C_PROCESS(it)->dead = 1;
			--vm->nb_champion;
		}
		else
			C_PROCESS(it)->live = 0;
		it = it->next;
	}
	++check;
	if ((vm->total_live >= NBR_LIVE) || (check == MAX_CHECKS))
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		DISPLAY_2 ? ft_printf("Cycle to die is now %d\n", vm->cycle_to_die) : 0;
		check = 0;
	}
	if (LOG_OPT)
	{
		ft_log("\t\tTotal lives : %d\n", vm->total_live);
		ft_log("\t\tCycle to die : %d\n", vm->cycle_to_die);
		ft_log("\t\tLast check : %d\n", check);
	}
	*cycle_end_round += vm->cycle_to_die;
	vm->total_live = 0;
	if (LOG_OPT)
	{
		#if 0
		it = vm->process_head.next;
		while (it != &vm->process_head)
		{
			ft_printf("process left : %d\n", C_PROCESS(it)->process_nb);
			it = it->next;
		}
		#endif
		ft_log("# --------------------------------------------------\n");

	}
}
