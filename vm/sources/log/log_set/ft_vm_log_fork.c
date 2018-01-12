/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:13:56 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/12 16:19:40 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_log.h"

void			ft_vm_log_fork(t_vm *vm, t_process const *proc)
{
	ft_log("  Cycle %-7d Player %2d --- %-5s\n", vm->current_cycle,
		-proc->process_nb, "fork");
	ft_log("\t\tProcess %d created at (%d %% MEM_SIZE) with IDX_MOD\n",
			-C_PROCESS(vm->process_head.next)->process_nb,
			MOD(proc->pc - vm->arena[0] + (proc->instr->args[0].data % IDX_MOD)));
	ft_log("\t\texec cycle at %d\n", C_PROCESS(vm->process_head.next)->exec_cycle);
	ft_log("\t\t------------------------------- %4d\n", proc->pc - vm->arena[0]);
}
