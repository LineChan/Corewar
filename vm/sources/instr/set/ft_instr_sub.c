/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:22:18 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/25 21:15:51 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void			ft_instr_sub(t_vm *vm, t_proc *proc)
{
	/* Compute the value and load it in a register */
	proc->reg[proc->instr->args[2].data] =
		proc->reg[proc->instr->args[0].data] - proc->reg[proc->instr->args[1].data];
	/* Display additional informations */
	if (DISP_OPT)
		ft_display_add_sub(vm, proc);
	/* Change the carry */
	proc->carry = !proc->reg[proc->instr->args[2].data];
}
