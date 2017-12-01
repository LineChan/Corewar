/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_lfork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:10:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/01 15:44:52 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void				ft_vm_instr_lfork(t_vm *vm, t_process *proc)
{
	extern uint8_t		g_direct_jump_table_from_instr[17];

	/* Create a new process, copy data from parent */
	/* and link it to the champion's structure at the right location */
	ft_vm_new_process_kid(vm, proc, MOD((proc->pc - vm->arena[0] +
	ft_instruction_get_data(g_direct_jump_table_from_instr[proc->op->numero],
									proc->pc + 1))));
	LOG_OPT ? ft_vm_log_lfork(vm, proc, proc->pc - vm->arena[0] +
	ft_instruction_get_data(g_direct_jump_table_from_instr[proc->op->numero],
									proc->pc + 1)) : 0;
	/* Fetch the next instruction */
	proc->pc += 5;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
