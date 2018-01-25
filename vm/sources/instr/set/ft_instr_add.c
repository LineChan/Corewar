/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:15:45 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/25 15:29:31 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void		ft_instr_add(t_vm *vm, t_proc *proc)
{
	/* Compute the result and load it in a register */
	if (REG_IS_VALID(proc->instr->args[0].data)
		&& REG_IS_VALID(proc->instr->args[1].data)
		&& REG_IS_VALID(proc->instr->args[2].data))
	{
		proc->reg[proc->instr->args[2].data] =
			proc->reg[proc->instr->args[0].data] + proc->reg[proc->instr->args[1].data];
	}
	else
		return ;
	/* Display additional informations */
	if (DISP_OPT)
		ft_display_add_sub(vm, proc);
	/* Change the carry */
	proc->carry = !proc->reg[proc->instr->args[2].data];
}
