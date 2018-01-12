/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_lfork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:10:32 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/12 16:17:30 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void				ft_vm_instr_lfork(t_vm *vm, t_process *proc, t_instr *instr)
{
	/* Create a new process, copy data from parent */
	/* and link it to the champion's structure at the right location */
	ft_vm_new_process_kid(vm, proc, MOD(proc->pc - vm->arena[0]
							+ instr->args[0].data));
	/* Display additional informations */
	if (DISP_OPT)
		ft_vm_display_lfork(vm, proc);
	/* Write in a logfile */
	ft_vm_log_lfork(vm, proc);
	/* Fetch the next instruction */
	proc->pc = instr->new_pc;
}
