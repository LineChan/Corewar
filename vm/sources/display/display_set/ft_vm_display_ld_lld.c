/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_ld_lld.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:48:18 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 12:49:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_printf.h"

void			ft_vm_display_ld_lld(t_vm *vm, t_process const *proc)
{
	if (DISPLAY_4)
	{
		ft_printf("P %4d | %s %d r%d\n",
					-proc->process_nb,
					proc->instr->op->name,
					proc->reg[proc->instr->args[1].data],
					proc->instr->args[1].data);
	}
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc);
}
