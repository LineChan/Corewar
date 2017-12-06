/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_xor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:36:48 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/05 19:15:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void			ft_vm_log_xor(t_vm *vm, t_process *proc,
								unsigned char *ptr,
								const int xor[2])
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
		-proc->process_nb, "add");
	ft_vm_log_arg(proc);
	ft_log("\t\treg[%d] = %d --> [%d] ^ [%d]\n", *ptr, proc->reg[*ptr],
		xor[0], xor[1]);
}
