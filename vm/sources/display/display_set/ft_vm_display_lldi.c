/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_lldi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:19:19 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 12:17:59 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void				ft_vm_display_lldi(t_vm *vm, t_process const *proc)
{
	if (DISPLAY_4)
	{
		ft_printf("P %4d | lldi %d %d r%d\n",
						-proc->process_nb,
						proc->instr->args[0].data,
						proc->instr->args[1].data,
						proc->instr->args[2].data);
		ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
						proc->instr->args[0].data,
						proc->instr->args[1].data,
						proc->instr->args[0].data + proc->instr->args[1].data,
						proc->pc - vm->arena[0] +
						proc->instr->args[0].data + proc->instr->args[1].data);
	}
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc);
}
