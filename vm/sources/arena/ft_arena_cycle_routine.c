/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_cycle_routine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:51:30 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/24 16:50:35 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

int				ft_arena_cycle_routine(t_vm *vm)
{
	/* Dump if necessary and the battle stops */
	if (vm->current_cycle == DUMP_OPT)
		return (ft_display_arena(vm));
	/* Increase the cycle counter */
	++vm->current_cycle;
	/* Display additional informations */
	if (DISPLAY_2)
		ft_printf("It is now cycle %d\n", vm->current_cycle);
	/* The instruction routine is applied on every proces */
	ft_list_apply_data(&vm->proc_head, (void *)vm, &ft_arena_instr_routine);
	return (EXIT_SUCCESS);
}
#if 0
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
#endif
