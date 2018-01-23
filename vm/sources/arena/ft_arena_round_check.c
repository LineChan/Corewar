/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_round_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:47:26 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/23 14:56:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void			ft_arena_round_check(t_vm *vm, int *cycle_end_round)
{
	t_list			*it;
	static int		check = 0;

	it = vm->proc_head.next;
	/* Loop on all the processes */
	while (it != &vm->proc_head)
	{
		/* If the process is still alive and its last live instruction was
			executed during the last round */
		if ((int)C_PROCESS(it)->has_lived < (vm->current_cycle - 1 - vm->cycle_to_die))
		{
			/* Delete the process if it did not call the live instruction */
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					-C_PROCESS(it)->proc_nb ,
					vm->current_cycle - 1 - C_PROCESS(it)->has_lived,
					vm->cycle_to_die);
			ft_del_proc(it);
			--vm->nb_proc;
		}
		/* Live count is reset */
		else
			C_PROCESS(it)->live = 0;
		it = it->next;
	}
	++check;
	/* If the total number of live instruction is bigger than NBR_LIVE
		or if cycle_to_die hasn't been decreased since MAX_CHECKS round */
	if ((vm->total_live >= NBR_LIVE) || (check == MAX_CHECKS))
	{
		/* cycle_to_die is decreased of CYCLE_DELTA */
		vm->cycle_to_die -= CYCLE_DELTA;
		if (DISPLAY_2)
			ft_printf("Cycle to die is now %d\n", vm->cycle_to_die);
		/* The number of checks is reset */
		check = 0;
	}
	/* Update the end of the next round */
	*cycle_end_round += vm->cycle_to_die;
}
