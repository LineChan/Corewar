/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_cycle_routine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:51:30 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/23 15:43:51 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void			ft_arena_cycle_routine(t_vm *vm)
{
	t_list		*it;

	it = vm->proc_head.next;
	if (DISPLAY_2)
		ft_printf("It is now cycle %d\n", vm->current_cycle);
	/* Loop on every process */
	while (it != &vm->proc_head)
	{
		//ft_printf("proc %d waiting exec->cycle : %d\n", C_PROCESS(it)->proc_nb, C_PROCESS(it)->exec_cycle);
		/* The instruction's routine is applied when its sleep time is over */
		#if 0
		if (C_PROCESS(it)->proc_nb == -18)
		ft_printf("proc 18 at : %d\n", C_PROCESS(it)->pc);
		#endif

		if (C_PROCESS(it)->exec_cycle == vm->current_cycle)
			ft_arena_instr_routine(vm, C_PROCESS(it));
		it = it->next;
	}
}
