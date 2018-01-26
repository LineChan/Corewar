/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_and.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:26:12 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/26 01:26:32 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void		ft_instr_and(t_vm *vm, t_proc *proc)
{
	/* Read arguments */
	ft_instr_and_or_xor_routine(vm, proc);
	/* Compute the result and store it in a register */
	proc->reg[proc->instr->args[2].data] =
		proc->instr->args[0].data & proc->instr->args[1].data;
	/* Change the carry */
	proc->carry = !proc->reg[proc->instr->args[2].data];
}
