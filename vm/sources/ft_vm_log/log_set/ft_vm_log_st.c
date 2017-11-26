/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_st.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:03:21 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/26 17:20:15 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void 				ft_vm_log_st(t_process *proc, const int dir)
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
							-proc->process_nb, proc->op->description);
	ft_vm_log_arg(proc);
	if (dir == T_DIR)
	{
		ft_log("\t\tarena[%d] = %d --> reg[%d]\n",
			MOD(proc->pc +
			(ft_instruction_get_data(2, proc->pc + 3) % IDX_MOD)),
			vm->arena[0][MOD(proc->pc +
			(ft_instruction_get_data(2, proc->pc + 3) % IDX_MOD)),
			*(proc->pc + 2))];
	}
	else
	{
		ft_log("\t\treg[%d] = %d --> reg[%d]\n",
				*(proc->pc + 3),
				proc->reg[*(proc->pc + 3)],
				*(proc->pc + 2));
	}
}
