/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_lfork.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:01:06 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/12 16:15:16 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void			ft_vm_display_lfork(t_vm *vm, t_process const *proc)
{
	if (DISPLAY_4)
	{
		ft_printf("P %4d | lfork %d (%d)\n",
					-proc->process_nb,
					proc->instr->args[0].data,
					proc->pc - vm->arena[0] + proc->instr->args[0].data);
	}
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc, proc->instr);
}
