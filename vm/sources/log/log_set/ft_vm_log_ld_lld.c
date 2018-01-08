/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_ld_lld.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:59:17 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/06 18:56:34 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"
#include "ft_instruction.h"

void		ft_vm_log_ld_lld(t_vm *vm, t_process const *proc)
{
	ft_log("  Cycle %-7d Process %2d --- %-5s\n",
						vm->current_cycle,
						-proc->process_nb,
						proc->instr->op->name);
	ft_vm_log_arg(proc->instr);
	if (proc->instr->args[0].type == IND_CODE)
	{
		ft_log("\t\treg[%d] = %d --> arena[%d %% MEM_SIZE]\n",
				proc->instr->args[1].data,
				proc->reg[proc->instr->args[1].data],
				proc->instr->args[0].data);
	}
	else
	{
		ft_log("\t\treg[%d] = %d\n",
			proc->instr->args[1].data,
			proc->reg[proc->instr->args[1].data]);
	}
	ft_log("\t\t------------------------------- %4d\n", proc->pc - vm->arena[0]);
}
