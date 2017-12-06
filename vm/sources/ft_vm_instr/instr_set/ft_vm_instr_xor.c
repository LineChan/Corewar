/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_xor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:21:54 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/05 19:27:32 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_vm_instr_xor(t_vm *vm, t_process *proc)
{
	int		xor[2];
	unsigned char		*ptr;

	ptr = 0;
	/* Read arguments */
	if (ft_vm_instr_and_or_xor_routine(vm, proc, &ptr, xor) == EXIT_FAILURE)
		return ;
	/* Compute the result and save it in a register */
	proc->reg[*ptr] = xor[0] ^ xor[1];
	/* Display additional informations */
	DISP_OPT ? ft_vm_display_xor(vm, proc, ptr, xor) : 0;
	/* Write in a log file */
	LOG_OPT ? ft_vm_log_xor(vm, proc, ptr, xor) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
	/* Change the carry */
	proc->carry ^= proc->carry;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
