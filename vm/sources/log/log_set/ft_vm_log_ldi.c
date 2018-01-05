/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_ldi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:06:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/22 16:33:43 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void					ft_vm_log_ldi(t_vm *vm,
										t_process const *proc,
										unsigned char const *ptr,
										const int tab[2])
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
		-proc->process_nb, "ldi");
	//ft_vm_log_arg(proc);
	ft_log("\t\treg[%d] =  %d --> arena[PC + %d %% MEM_SIZE]\n",
						*ptr, proc->reg[*ptr], tab[0] + tab[1]);
	ft_log("\t\tpc at : %d\n", proc->pc - vm->arena[0]);
}
