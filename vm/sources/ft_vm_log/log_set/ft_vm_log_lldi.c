/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_lldi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:40:21 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/30 14:19:58 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void			ft_vm_log_lldi(t_vm *vm, t_process *proc,
								const unsigned char *ptr,
								const unsigned int address)
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
		-proc->process_nb, "lldi");
	ft_vm_log_arg(proc);
	ft_log("\t\treg[%d] = %d --> arena[%d + %d %% MEM_SIZE]\n",
												*ptr, proc->reg[*ptr],
												proc->pc - vm->arena[0], address);
}
