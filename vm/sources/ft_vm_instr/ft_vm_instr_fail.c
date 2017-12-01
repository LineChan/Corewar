/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_fail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:10:06 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/01 15:48:23 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : libs
#include <libc.h>
#include "ft_printf.h"
void 				ft_vm_instr_fail(t_vm *vm,
									t_process *proc,
									const int carry_change)
{
	(void)vm;
	/* Move the Program Counter to the next byte */
	proc->pc += 1;
	/* Set the instruction cycle to the next one */
	ft_vm_instr_update_exec_cycle(vm, proc);
	/* Set the carry to 1 if necessary */
	(carry_change == CARRY_CHANGE) ? (proc->carry = 1) : 0;
}
	#if 0
	if ((proc->pc - vm->arena[0]) == MEM_SIZE)
	{
		ft_fprintf(2, "proc %d at the end of the arena !\n", proc->parent_nb);
		proc->pc = vm->arena[0];
		ft_vm_instr_update_exec_cycle(proc);
		ft_fprintf(2, "next exec cycle : %d\n", proc->exec_cycle);
	}
	else
	{
		/* Set the instruction cycle to the next one */
		proc->exec_cycle += 1;
	}
	/* Set the carry to 1 if necessary */
	(carry_change == CARRY_CHANGE) ? (proc->carry = 1) : 0;
	#endif
