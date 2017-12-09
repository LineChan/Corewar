/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_and.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:26:51 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 15:34:17 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_vm_instr_and(t_vm *vm, t_process *proc)
{
	int	and[2];
	unsigned char	*ptr;

	ptr = 0;
	/* Read arguments */
	if (ft_vm_instr_and_or_xor_routine(vm, proc, &ptr, and) == EXIT_FAILURE)
		return ;
	/* Compute the result and store it in a register */
	proc->reg[*ptr] = and[0] & and[1];
	/* Display additional informations */
	DISP_OPT ? ft_vm_display_and(vm, proc, ptr, and) : 0;
	/* Write in the log file */
	LOG_OPT ? ft_vm_log_and(vm, proc, ptr, and) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
	/* Change the carry */
	proc->carry = 0;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
