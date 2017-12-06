/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_or.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:31:29 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/06 12:56:49 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : libs;
#include "ft_printf.h"
void				ft_vm_instr_or(t_vm *vm, t_process *proc)
{
	int					or[2];
	unsigned char		*ptr;

	ptr = 0;
	/* Read arguments */
	if (ft_vm_instr_and_or_xor_routine(vm, proc, &ptr, or) == EXIT_FAILURE)
		return ;
	/* Compute the result and load it in a register */
	proc->reg[*ptr] = or[0] | or[1];
	/* Display additional informations */
	DISP_OPT ? ft_vm_display_or(vm, proc, ptr, or) : 0;
	/* Write in the log file */
	LOG_OPT ? ft_vm_log_or(vm, proc, ptr, or) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
	/* Change the carry */
	proc->carry ^= proc->carry;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
