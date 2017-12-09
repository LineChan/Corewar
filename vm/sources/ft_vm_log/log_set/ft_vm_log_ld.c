/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_ld.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:33:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 16:26:45 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void			ft_vm_log_ld(t_vm *vm,
							t_process const *proc,
							unsigned char const *ptr,
							const unsigned int address)
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
		-proc->process_nb, "ld");
	ft_vm_log_arg(proc);
	ft_log("\t\treg[%d] = %d --> (arena[%d %% IDX_MOD])\n", *ptr, proc->reg[*ptr], MOD(address));
}
