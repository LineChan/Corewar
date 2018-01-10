/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_and.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:58:42 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/22 16:33:27 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void			ft_vm_log_and(t_vm *vm,
								t_process const *proc,
								unsigned char const *ptr,
								const int and[2])
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
		-proc->process_nb, "and");
	//ft_vm_log_arg(proc);
	ft_log("\t\treg[%d] = %d --> [%d] & [%d]\n",
		*ptr, proc->reg[*ptr], and[0], and[1]);
}