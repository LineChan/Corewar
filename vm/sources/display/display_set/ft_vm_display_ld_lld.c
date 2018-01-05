/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_ld_lld.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:48:18 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/21 14:54:45 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void			ft_vm_display_ld_lld(t_vm *vm,
								t_process const *proc,
								t_instr const *instr)
{
	if (DISPLAY_4)
	{
		if (instr->args[0].type == IND_CODE)
		{
			ft_printf("P %4d | %s %d r%d\n",
						-proc->process_nb,
						instr->op->name,
						proc->reg[instr->args[1].data],
						instr->args[1].data);
		}
		else
		{
			ft_printf("P %4d | %s %d r%d\n",
						-proc->process_nb,
						instr->op->name,
						instr->args[0].data,
						instr->args[1].data);
		}
	}
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc, instr);
}
