/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_live.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 23:50:37 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/26 01:16:46 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void			ft_vm_log_live(t_vm *vm, t_process *proc, t_list *it)
{
	if (it)
	{
		ft_log("  Cycle %-7d Process %d --- %-5s : Player %d\n",
							vm->current_cycle,
							-proc->process_nb,
							proc->op->description,
							-C_PROCESS(it)->process_nb);
	}
	ft_log("  Cycle %-7d Process %d --- %-5s : failed\n",
						vm->current_cycle,
						-proc->process_nb,
						proc->op->description);

}
