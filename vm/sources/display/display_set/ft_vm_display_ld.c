/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_ld.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:48:18 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/17 14:23:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

static void		ft_vm_display_instr(t_process const *proc, t_instr const *instr)
{
	if (instr->args[0].type == IND_CODE)
	{
		ft_printf("P    %d | ld %d r%d\n",
					proc->parent_nb,
					proc->reg[instr->args[1].data],
					instr->args[1].data);
		return ;
	}
	ft_printf("P    %d | ld %d r%d\n",
				proc->parent_nb,
				instr->args[0].data,
				instr->args[1].data);
}

void			ft_vm_display_ld(t_vm *vm,
								t_process const *proc,
								t_instr const *instr)
{
	if (DISPLAY_4)
		ft_vm_display_instr(proc, instr);
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc, instr);
}
