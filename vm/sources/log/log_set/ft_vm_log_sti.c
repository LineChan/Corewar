/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_sti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:42:38 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/22 16:35:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void				ft_vm_log_sti(t_vm *vm,
									t_process const *proc,
									const int copy_at_address[2])
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
		-proc->process_nb, "sti");
	//ft_vm_log_arg(proc);
	ft_log("\t\tarena[%d + %d] = %d --> reg[%d]\n",
						copy_at_address[0], copy_at_address[1],
						vm->arena[0][MOD(copy_at_address[0] + copy_at_address[1])],
						*(proc->pc + 2));
}
