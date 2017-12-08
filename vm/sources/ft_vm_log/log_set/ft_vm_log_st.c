/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_st.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:03:21 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/07 23:46:32 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void 				ft_vm_log_st(t_vm *vm, t_process *proc)
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
							-proc->process_nb, "st");
	ft_vm_log_arg(proc);
	if (proc->op->arg_types[1]== T_IND)
	{
		ft_log("\t\tarena[%d] = %d --> reg[%d]\n",
			MOD((proc->pc - vm->arena[0]+ (ft_vm_instr_get_data(2, proc->pc + 3, vm) % IDX_MOD))),
			vm->arena[0][MOD(proc->pc - vm->arena[0] + ft_vm_instr_get_data(2, proc->pc + 3, vm) % IDX_MOD)],
			*(proc->pc + 2));
	}
	else
	{
		ft_log("\t\treg[%d] = %d --> reg[%d]\n",
				*(proc->pc + 3),
				proc->reg[*(proc->pc + 3)],
				*(proc->pc + 2));
	}
}
