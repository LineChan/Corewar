/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 23:16:48 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/06 14:46:34 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_vm_instr_add(t_vm *vm, t_process *proc)
{
	int		add[3];
	unsigned char		*ptr;

	ptr = 0;
	if (ft_vm_instr_add_sub_routine(vm, proc, &ptr, add) == EXIT_FAILURE)
		return ;
	/* Compute the result and load it in a register */
	proc->reg[add[2]] = MOD(proc->reg[add[0]] + proc->reg[add[1]]);
	/* Display additional informations */
	DISP_OPT ? ft_vm_display_add(vm, proc, add) : 0;
	/* Write in a log file */
	LOG_OPT ? ft_vm_log_add(vm, proc, add) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
	/* Change the carry */
	proc->carry ^= proc->carry;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
