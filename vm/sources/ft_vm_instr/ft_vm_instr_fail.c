/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_fail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:10:06 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 15:28:20 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void 				ft_vm_instr_fail(t_vm *vm,
									t_process *proc,
									const int size,
									const int carry_change)
{
	/* Display additional informations */
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc, size);
	/* Fetch the next instruction */
	proc->pc += size;
	/* Set the instruction cycle to the next one */
	ft_vm_instr_update_exec_cycle(vm, proc);
	/* Set the carry to 1 if necessary */
	if (carry_change)
		proc->carry = 1;
}
