/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:13:56 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/22 16:33:32 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void			ft_vm_log_fork(t_vm *vm,
								t_process const *proc,
								const int index)
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
		-proc->process_nb, "fork");
	//ft_vm_log_arg(proc);
	ft_log("\t\tProcess %d created at (%d %% MEM_SIZE)\n", -C_PROCESS(vm->process_head.next)->process_nb, index);
	ft_log("\t\texec cycle at %d\n", C_PROCESS(vm->process_head.next)->exec_cycle);
}
