/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_aff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:28:37 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/18 18:43:14 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void			ft_vm_instr_aff(t_vm *vm, t_process *proc, t_instr *instr)
{
	ft_printf("%c\n", proc->reg[instr->args[0].data] % 256);
	/* Display additional informations */
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc, instr);

	/* Write in a logfile */
	// TODO : logfile
	/* Fetch the next instruction */
	proc->pc = instr->new_pc;
	/* Change the carry */
	proc->carry = 0;
	/* Update the instruction cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
	#if 0
	(void)instr;
	/* Check is the value is a register number */
	if (!IS_REG(*(proc->pc + 2)))
	{
		ft_vm_instr_fail(vm, proc, 2 + proc->jump[0],!CARRY_CHANGE);
		return ;
	}
	ft_printf("%c\n", proc->reg[*(proc->pc + 2)] % 256);
	/* Display additional informations */
	if (DISP_OPT)
	{
		//DISPLAY_1
		// DISPLAY_8
		DISPLAY_16 ? ft_vm_display_pc(vm, proc, 2 + proc->jump[0]) : 0;
	}
	/* Write in a log file */
	LOG_OPT ? ft_vm_log_aff(vm, proc) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0];
	/* Change the carry */
	proc->carry ^= proc->carry;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
	#endif
}