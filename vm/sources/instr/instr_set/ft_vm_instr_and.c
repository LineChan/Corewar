/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_and.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:26:51 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/11 00:05:53 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void			ft_vm_instr_and(t_vm *vm, t_process *proc, t_instr *instr)
{
	/* Read arguments */
	ft_vm_instr_and_or_xor_routine(vm, proc, instr);
	/* Display additional informations */
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc, instr);
	/* Compute the result and store it in a register */
	proc->reg[instr->args[2].data] = instr->args[0].data & instr->args[1].data;
	/* Write in the log file */
	//TODO : logfile
	//LOG_OPT ? ft_vm_log_and(vm, proc, ptr, and) : 0;
	/* Fetch the next instruction */
	proc->pc = instr->new_pc;
	/* Change the carry */
	proc->carry = !proc->reg[instr->args[2].data];
}
