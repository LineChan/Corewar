/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_round_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:51:33 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/26 16:36:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : libs
#include "ft_printf.h"
#include <libc.h>
#include "ft_log.h"
void			ft_vm_arena_round_check(t_vm *vm,
										int *nb_champion,
										unsigned int *cycle_end_round,
										unsigned int *cycle_to_die)
{
	t_list				*it;
	unsigned int		live_total;

	it = vm->process_head.next;
	live_total = 0;
	while (it != &vm->process_head)
	{
		if (!C_PROCESS(it)->live)
		{
			/* Delete the process if it did not call the live instruction */
			//ft_printf("deleting %d\n", C_PROCESS(it)->process_nb);
			LOG_OPT ?
				ft_log("Check Round at %d: Player %d is dead\n",
				vm->current_cycle,
				C_PROCESS(it)->process_nb) : 0 ;
			ft_vm_close_process(it);
			--*nb_champion;
		}
		else
		{
			/* Count the number of live done and set it up for the next round */
			live_total += C_PROCESS(it)->live;
			#if 0
			ft_printf("check : %d ---> %d lives\n", C_PROCESS(it)->parent_nb,
						C_PROCESS(it)->live);
			#endif
			C_PROCESS(it)->live ^= C_PROCESS(it)->live;
		}
		it = it->next;
	}
	if (live_total >= NBR_LIVE)
		*cycle_to_die -= CYCLE_DELTA;
	*cycle_end_round += *cycle_to_die;
	ft_printf("end_round : %d\n", *cycle_end_round);
	getchar();
}
