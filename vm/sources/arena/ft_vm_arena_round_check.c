/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_round_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:51:33 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 14:52:52 by mvillemi         ###   ########.fr       */
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
	/* Loop on all the processes */
	while (it != &vm->process_head)
	{
		/* If the process is still alive and its last live instruction was */
		/* executed during the last round */
		if (!C_PROCESS(it)->dead
			&& ((int)C_PROCESS(it)->has_lived < (vm->current_cycle - vm->cycle_to_die)))
		{
			/* Delete the process if it did not call the live instruction */
			if (LOG_OPT)
				ft_log("\t\tProcess %d is dead\n", -C_PROCESS(it)->process_nb);
				//TODO : DISPLAY ??
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					-C_PROCESS(it)->process_nb ,
					vm->current_cycle - 1 - C_PROCESS(it)->has_lived,
					vm->cycle_to_die);
			C_PROCESS(it)->dead = 1;
			--vm->nb_champion;
		}
		/* Live count is reset */
		else
			C_PROCESS(it)->live = 0;
		it = it->next;
	}
	++check;
	/* If the total number of live instruction is bigger than NBR_LIVE */
	/* or if cycle_to_die hasn't been decreased since MAX_CHECKS round */
	if ((vm->total_live >= NBR_LIVE) || (check == MAX_CHECKS))
	{
		/* cycle_to_die is decreased of CYCLE_DELTA */
		vm->cycle_to_die -= CYCLE_DELTA;
		DISPLAY_2 ? ft_printf("Cycle to die is now %d\n", vm->cycle_to_die) : 0;
		/* The number of checks is reset */
		check = 0;
	}
	if (LOG_OPT)
	{
		ft_log("\t\tTotal lives : %d\n", vm->total_live);
		ft_log("\t\tCycle to die : %d\n", vm->cycle_to_die);
		ft_log("\t\tLast check : %d\n", check);
	}
	/* Update the end of the next round */
	*cycle_end_round += vm->cycle_to_die;
	/* The total number of live instruction is reset */
	vm->total_live = 0;
	if (LOG_OPT)
	{
		ft_log("# --------------------------------------------------\n");
	}
}
