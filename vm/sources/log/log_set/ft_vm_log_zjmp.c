/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_zjmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:12:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/22 16:55:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"
#include "ft_instruction.h"

void			ft_vm_log_zjmp(t_vm *vm,
								t_process const *proc,
								t_instr const *instr)
{
	extern uint8_t g_direct_jump_table_from_instr[17];

	if (proc->carry)
	{
		ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
			-proc->process_nb, "zjmp");
	}
	else
	{
		ft_log("  Cycle %-7d Player %d --- %-5s KO\n", vm->current_cycle,
			-proc->process_nb, "zjmp");
	}
	ft_vm_log_arg(instr);
	ft_log("\t\tJump of (%d + (%d %% IDX_MOD) : %d\n", proc->pc - vm->arena[0],
		instr->args[0].data,
		MOD(proc->pc - vm->arena[0] + (instr->args[0].data % IDX_MOD)));
}
