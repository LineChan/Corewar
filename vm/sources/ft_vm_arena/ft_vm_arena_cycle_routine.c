/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_cycle_routine.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:27:43 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/01 10:31:46 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

// TODO:remove libs
#include "ft_printf.h"
#include <libc.h>

void			ft_vm_arena_cycle_routine(t_vm *vm)
{
	t_list		*it;

	it = vm->process_head.next;
	while (it != &vm->process_head)
	{
		ft_fprintf(2, "process (%d)-> g_op_tab[%hhx] exec cycle : %d current_cycle : %d\n",
			-C_PROCESS(it)->process_nb, *C_PROCESS(it)->pc,
			C_PROCESS(it)->exec_cycle, vm->current_cycle);
		if (C_PROCESS(it)->exec_cycle == vm->current_cycle)
		{
			ft_vm_arena_instr_routine(vm, C_PROCESS(it));
			if (DISP_OPT)
			{
				if (C_PROCESS(it)->pc == &vm->arena[0][vm->index[C_PROCESS(it)->parent_nb - 1 + CHAMP_MAX_SIZE]])
					++C_PROCESS(it)->pc;
			}
		}
		it = it->next;
	}
}
