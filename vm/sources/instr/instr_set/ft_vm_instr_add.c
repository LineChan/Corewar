/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 23:16:48 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/11 00:04:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

//TODO:libs
#include "ft_printf.h"
void			ft_vm_instr_add(t_vm *vm, t_process *proc, t_instr *instr)
{
	//ft_printf("{yellow:instr_add}\n");
	/* Compute the result and load it in a register */
	proc->reg[instr->args[2].data] =
		proc->reg[instr->args[0].data] + proc->reg[instr->args[1].data];
	/* Display additional informations */
	if (DISP_OPT)
		ft_vm_display_add(vm, proc, instr);
	/* Write in the log file */
	//TODO : log
	/* Fetch the next instruction */
	proc->pc = instr->new_pc;
	/* Change the carry */
	//TODO : check the carry change
	if (!(instr->args[0].data + instr->args[1].data))
		proc->carry = 1;
	else
		proc->carry = 0;
}
