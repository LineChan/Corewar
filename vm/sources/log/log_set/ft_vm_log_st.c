/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_st.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:03:21 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/08 21:45:30 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_log.h"

void 				ft_vm_log_st(t_vm *vm, t_process const *proc)
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
							-proc->process_nb, "st");
	if (proc->op->arg_types[1]== T_IND)
	{
		ft_log("\t\tarena[%d] = %d --> reg[%d]\n",
			MOD((proc->pc - vm->arena[0]+ (proc->instr->args[1].data % IDX_MOD))),
			vm->arena[0][MOD(proc->pc - vm->arena[0] + (proc->instr->args[1].data % IDX_MOD))],
			proc->instr->args[0].data);
	}
	else
	{
		ft_log("\t\treg[%d] = %d --> reg[%d]\n",
				proc->instr->args[1].data,
				proc->reg[proc->instr->args[1].data],
				proc->instr->args[0].data);
	}
}
