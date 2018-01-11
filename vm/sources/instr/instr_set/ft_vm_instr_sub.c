/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 23:47:39 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/11 00:10:21 by mvillemi         ###   ########.fr       */
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
	proc->carry = !proc->reg[instr->args[2].data];
}
