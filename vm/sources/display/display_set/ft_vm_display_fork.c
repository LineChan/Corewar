/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_fork.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:56:36 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 12:50:29 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void			ft_vm_display_fork(t_vm *vm, t_process const *proc)
{
	if (DISPLAY_4)
	{
		ft_printf("P %4d | fork %d (%d)\n",
					-proc->process_nb,
					proc->instr->args[0].data,
					proc->pc - vm->arena[0] + (proc->instr->args[0].data % IDX_MOD));
	}
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc);
}
