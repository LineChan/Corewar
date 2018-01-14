/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:52:21 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 12:22:33 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void				ft_vm_instr_fork(t_vm *vm, t_process *proc)
{
	/* Create a new process, copy data from parent */
	/* and link it to the champion's structure at the right location */
	ft_vm_new_process_kid(vm, proc, MOD(proc->pc - vm->arena[0] +
			(proc->instr->args[0].data % IDX_MOD)));
	/* Display additional informations */
	if (DISP_OPT)
		ft_vm_display_fork(vm, proc);
		#if 0
	/* Write in the log file */
	if (LOG_OPT)
		ft_vm_log_fork(vm, proc);
		#endif
	/* Fetch the new instruction */
	proc->pc = proc->instr->new_pc;
}
