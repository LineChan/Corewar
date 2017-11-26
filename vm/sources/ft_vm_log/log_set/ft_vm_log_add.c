/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 23:26:55 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/26 23:37:15 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void 				ft_vm_log_add(t_vm *vm,
									t_process *proc,
									const unsigned int add[3])
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
		-proc->process_nb, proc->op->description);
	ft_vm_log_arg(proc);
	ft_log("\t\treg[%d] = %d --> [%d] + [%d]\n", add[2], proc->reg[add[2]], add[0], add[1]);
}
