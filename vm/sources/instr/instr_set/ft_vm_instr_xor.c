/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_xor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:21:54 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 16:03:41 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void			ft_vm_instr_xor(t_vm *vm, t_process *proc)
{
	/* Read arguments */
	ft_vm_instr_and_or_xor_routine(vm, proc);
	/* Compute the result and store it in a register */
	proc->reg[proc->instr->args[2].data] =
		proc->instr->args[0].data ^ proc->instr->args[1].data;
	/* Fetch the next instruction */
	proc->pc = proc->instr->new_pc;
	/* Change the carry */
	proc->carry = !proc->reg[proc->instr->args[2].data];
}
