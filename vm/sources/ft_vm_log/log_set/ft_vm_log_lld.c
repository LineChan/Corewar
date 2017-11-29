/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_lld.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:08:43 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/29 14:49:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void				ft_vm_log_lld(t_vm *vm,
								t_process *proc,
								const unsigned char *ptr,
								const unsigned int value_to_load)
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
		-proc->process_nb, "or");
	ft_vm_log_arg(proc);
	ft_log("\t\treg[%d] = %d --> arena[%d %% MEM_SIZE]\n", *ptr, proc->reg[*ptr],
																value_to_load);
}
