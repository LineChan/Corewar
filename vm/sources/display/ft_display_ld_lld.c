/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_ld_lld.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:14:39 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/19 10:17:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_printf.h"

void			ft_display_ld_lld(t_vm *vm, t_proc const *proc)
{
	if (DISPLAY_4)
	{
		ft_printf("P %4d | %s %d r%d\n",
				-proc->proc_nb,
				proc->instr->op->name,
				proc->reg[proc->instr->args[1].data],
				proc->instr->args[1].data);
	}
	if (DISPLAY_16)
		ft_display_pc(vm, proc);
}
