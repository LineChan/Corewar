/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_cycle_routine.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:27:43 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 22:52:22 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

//TODO: libs
#include "ft_printf.h"
#include "ft_instruction.h"

void			ft_vm_arena_cycle_routine(t_vm *vm)
{
	t_list		*it;

	it = vm->process_head.next;
	if (DISPLAY_2)
		ft_printf("It is now cycle %d\n", vm->current_cycle);
	/* Loop on every process */
	while (it != &vm->process_head)
	{
		#if 0
		if (C_PROCESS(it)->process_nb == -3)
		{

			ft_printf("next_op : %d at PC %d\n", C_PROCESS(it)->next_op, C_PROCESS(it)->pc - vm->arena[0]);
			ft_printf("exec_cycle : %d\n", C_PROCESS(it)->exec_cycle);
		}
		#endif
		/* The instruction's routine is applied when its sleep time is over */
		if ((C_PROCESS(it)->exec_cycle == vm->current_cycle)
				&& !C_PROCESS(it)->dead)
			ft_vm_arena_instr_routine(vm, C_PROCESS(it));
		//ft_printf("exec_cycle out : %d and new_op : %d\n", C_PROCESS(it)->exec_cycle, C_PROCESS(it)->instr->new_pc);
		#if 0
		if (C_PROCESS(it)->process_nb == -3)
			ft_printf("new exec_cycle : %d\n\n", C_PROCESS(it)->exec_cycle);
		#endif
		it = it->next;
	}
}
