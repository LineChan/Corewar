/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:52:21 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/01 15:44:55 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void				ft_vm_instr_fork(t_vm *vm, t_process *proc)
{
	extern uint8_t g_direct_jump_table_from_instr[17];

	/* Create a new process, copy data from parent */
	/* and link it to the champion's structure at the right location */
	ft_vm_new_process_kid(vm, proc, MOD((proc->pc - vm->arena[0] +
	(ft_instruction_get_data(g_direct_jump_table_from_instr[proc->op->numero],
									proc->pc + 1) % IDX_MOD))));
	/* Write in a log file */
	LOG_OPT ? ft_vm_log_lfork(vm, proc, proc->pc - vm->arena[0] +
	(ft_instruction_get_data(g_direct_jump_table_from_instr[proc->op->numero],
									proc->pc + 1) % IDX_MOD)) : 0;
	/* Fetch the next instruction */
	proc->pc += 5;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
