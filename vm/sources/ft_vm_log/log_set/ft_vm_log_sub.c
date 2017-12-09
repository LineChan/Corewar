/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:04:13 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 16:27:52 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void			ft_vm_log_sub(t_vm *vm,
								t_process const *proc,
								const int sub[3])
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
		-proc->process_nb, "sub");
	ft_vm_log_arg(proc);
	ft_log("\t\treg[%d] = %d --> [%d] - [%d]\n", sub[2],
				proc->reg[sub[2]], sub[0], sub[1]);
}
