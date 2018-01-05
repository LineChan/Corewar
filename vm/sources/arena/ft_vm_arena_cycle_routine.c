/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_cycle_routine.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:27:43 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/05 22:50:36 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

//TODO: libs
#include "ft_printf.h"

void			ft_vm_arena_cycle_routine(t_vm *vm)
{
	t_list		*it;

	it = vm->process_head.next;
	while (it != &vm->process_head)
	{
		if ((C_PROCESS(it)->exec_cycle == vm->current_cycle)
				&& !C_PROCESS(it)->dead)
		{
			//ft_printf("Player %d\n", C_PROCESS(it)->process_nb);
			ft_vm_arena_instr_routine(vm, C_PROCESS(it));
		}
		it = it->next;
	}
}
