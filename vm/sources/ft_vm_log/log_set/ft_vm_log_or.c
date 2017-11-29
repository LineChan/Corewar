/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:51:00 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/29 14:13:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void 			ft_vm_log_or(t_vm *vm, t_process *proc,
							const unsigned char *ptr,
							const unsigned int or[2])

{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
		-proc->process_nb, "or");
	ft_vm_log_arg(proc);
	ft_log("\t\treg[%d] = %d --> [%d] | [%d]\n", *ptr, proc->reg[*ptr],
													or[0], or[1]);
}
