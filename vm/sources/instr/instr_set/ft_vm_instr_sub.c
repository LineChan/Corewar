/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 23:47:39 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/19 18:14:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void			ft_vm_instr_sub(t_vm *vm, t_process *proc, t_instr *instr)
{
	/* Compute the value and load it in a register */
	proc->reg[instr->args[2].data] =
		MOD((proc->reg[instr->args[0].data] - proc->reg[instr->args[1].data]));
	/* Display additional informations */
	if (DISP_OPT)
		ft_vm_display_sub(vm, proc, instr);
	/* Write in the log file */
	//TODO : log
	/* Fetch the next instruction */
	proc->pc = instr->new_pc;
	/* Change the carry */
	//TODO : check the carry change
	if (!(instr->args[0].data + instr->args[1].data))
		proc->carry = 1;
	else
		proc->carry = 0;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
