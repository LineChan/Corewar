/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_cycle_routine.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:27:43 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/26 01:22:37 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
// TODO:remove printf
#include "ft_printf.h"
#include <libc.h>

void			ft_vm_arena_cycle_routine(t_vm *vm)
{
	t_list		*it;

	it = vm->process_head.next;
	while (it != &vm->process_head)
	{
		ft_printf("process (%d)-> g_op_tab[%hhx] exec cycle : %d current_cycle : %d\n",
			-C_PROCESS(it)->process_nb, *C_PROCESS(it)->pc,
			C_PROCESS(it)->exec_cycle, vm->current_cycle);
		if (C_PROCESS(it)->exec_cycle == vm->current_cycle)
		{
			ft_vm_arena_instr_routine(vm, C_PROCESS(it));
			ft_printf("cycle_routine\n");
			//getchar();
		}
		it = it->next;
	}
}
