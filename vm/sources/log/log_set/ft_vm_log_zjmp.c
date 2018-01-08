/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_zjmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:12:14 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/06 18:04:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"
#include "ft_instruction.h"

void			ft_vm_log_zjmp(t_vm *vm, t_process const *proc)
{
	if (!proc->carry)
	{
		ft_log("  Cycle %-7d Process %2d --- %-5s FAILED\n",
							vm->current_cycle,
							-proc->process_nb,
							"zjmp");
		ft_log("\t\t------------------------------- %4d\n", proc->pc - vm->arena[0]);
	}
	else
	{
		ft_log("  Cycle %-7d Player %d --- %-5s\n",
			vm->current_cycle,
			-proc->process_nb, "zjmp");
		ft_vm_log_arg(proc->instr);
		ft_log("\t\tJump of (%d + (%d %% IDX_MOD))\n",
				proc->pc - vm->arena[0], proc->instr->args[0].data);
		ft_log("\t\t------------------------------- %4d\n",
		MOD(proc->pc - vm->arena[0] + (proc->instr->args[0].data % IDX_MOD)));
	}
}
