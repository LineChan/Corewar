/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 23:16:48 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 12:47:49 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void			ft_vm_instr_add(t_vm *vm, t_process *proc)
{
	/* Compute the result and load it in a register */
	proc->reg[proc->instr->args[2].data] =
		proc->reg[proc->instr->args[0].data] + proc->reg[proc->instr->args[1].data];
	/* Display additional informations */
	if (DISP_OPT)
		ft_vm_display_add(vm, proc);
		#if 0
	/* Write in the log file */
	//TODO : log
	#endif
	/* Fetch the next instruction */
	proc->pc = proc->instr->new_pc;
	/* Change the carry */
	proc->carry = !proc->reg[proc->instr->args[2].data];
}
