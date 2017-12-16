/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_zjmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:48:01 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/15 17:48:16 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_vm_instr_zjmp(t_vm *vm, t_process *proc, t_instr *instr)
{
	(void)vm;
	(void)proc;
	(void)instr;
	#if 0
	extern uint8_t g_direct_jump_table_from_instr[17];

	(void)instr;
	/* Execute the instruction only if the carry value is 1 */
	if (proc->carry)
		proc->pc += MOD((proc->pc - vm->arena[0] + (ft_vm_instr_get_data(g_direct_jump_table_from_instr[proc->op->numero], proc->pc + 1, vm) % IDX_MOD)));
	/* Write in the log file */
	LOG_OPT ? ft_vm_log_zjmp(vm, proc) : 0;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
	#endif
}
