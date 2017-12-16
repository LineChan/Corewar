/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_or.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:31:29 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/15 17:43:48 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO:libs
#include "ft_printf.h"
void				ft_vm_instr_or(t_vm *vm, t_process *proc, t_instr *instr)
{
	/* Read arguments */
	ft_vm_instr_and_or_xor_routine(vm, proc, instr);
	/* Display additional informations */
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc, instr);
	/* Compute the result and store it in a register */
	proc->reg[instr->args[2].data] = instr->args[0].data | instr->args[1].data;
	// TODO : logfile
	/* Fetch the next instruction */
	proc->pc = instr->new_pc;
	/* Change the carry */
	proc->carry = 0;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
