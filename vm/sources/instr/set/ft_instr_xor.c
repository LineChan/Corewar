/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_xor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:08:40 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/25 15:29:39 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void			ft_instr_xor(t_vm *vm, t_proc *proc)
{
	/* Read arguments */
	ft_instr_and_or_xor_routine(vm, proc);
	/* Compute the restult and store it in a register */
	if (REG_IS_VALID(proc->instr->args[2].data))
	{
		proc->reg[proc->instr->args[2].data] =
			proc->instr->args[0].data ^ proc->instr->args[1].data;
	}
	else
		return ;
	/* Change the carry */
	proc->carry = !proc->reg[proc->instr->args[2].data];
}
