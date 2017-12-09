/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_zjmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:12:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 16:28:04 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void			ft_vm_log_zjmp(t_vm *vm, t_process const *proc)
{
	extern uint8_t g_direct_jump_table_from_instr[17];

	ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
		-proc->process_nb, "zjmp");
	ft_vm_log_arg(proc);
	ft_log("\t\tJump of %d %% IDX_MOD\n", ft_vm_instr_get_data(g_direct_jump_table_from_instr[proc->op->numero], proc->pc + 1, vm));
}
