/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_live.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 23:50:37 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/05 22:36:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void			ft_vm_log_live(t_vm *vm,
								t_process const *proc,
								t_list const *it)
{
	if (it)
	{
		ft_log("  Cycle %-7d Process %2d --- %-5s : Player %d\n",
							vm->current_cycle,
							-proc->process_nb,
							"live",
							-C_PROCESS(it)->process_nb);
	}
	else
	{
		ft_log("  Cycle %-7d Process %2d --- %-5s : failed\n",
							vm->current_cycle,
							-proc->process_nb,
							"live");
	}
}
