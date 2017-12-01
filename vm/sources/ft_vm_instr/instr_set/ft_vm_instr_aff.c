/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_aff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:28:37 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/01 15:42:25 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void			ft_vm_instr_aff(t_vm *vm, t_process *proc)
{
	/* Check is the value is a register number */
	if (!IS_REG(*(proc->pc + 2)))
	{
		ft_vm_instr_fail(vm, proc, !CARRY_CHANGE);
		return ;
	}
	ft_printf("%c\n", proc->reg[*(proc->pc + 2)] % 256);
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0];
	/* Write in a log file */
	LOG_OPT ? ft_vm_log_aff(vm, proc) : 0;
	/* Change the carry */
	proc->carry ^= proc->carry;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
