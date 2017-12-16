/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_aff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:38:07 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 16:26:22 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void				ft_vm_log_aff(t_vm *vm, t_process const *proc)
{
	ft_log("  Cycle %-7d Player %d --- %-5s : %hhx\n", vm->current_cycle,
		-proc->process_nb, "aff", *(proc->pc + 2) % 256);
	ft_vm_log_arg(proc);
}
