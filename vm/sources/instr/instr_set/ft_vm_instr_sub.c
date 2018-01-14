/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 23:47:39 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 12:42:28 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void			ft_vm_instr_sub(t_vm *vm, t_process *proc)
{
	/* Compute the value and load it in a register */
	proc->reg[proc->instr->args[2].data] =
		proc->reg[proc->instr->args[0].data] - proc->reg[proc->instr->args[1].data];
	/* Display additional informations */
	if (DISP_OPT)
		ft_vm_display_sub(vm, proc);
	/* Write in the log file */
	//TODO : log
	/* Fetch the next instruction */
	proc->pc = proc->instr->new_pc;
	/* Change the carry */
	proc->carry = !proc->reg[proc->instr->args[2].data];
}
