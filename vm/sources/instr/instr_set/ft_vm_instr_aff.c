/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_aff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:28:37 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 12:58:28 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_printf.h"

void			ft_vm_instr_aff(t_vm *vm, t_process *proc)
{
	ft_printf("%c\n", proc->reg[proc->instr->args[0].data] % 256);
	/* Display additional informations */
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc);
	/* Write in a logfile */
	// TODO : logfile
	/* Fetch the next instruction */
	proc->pc = proc->instr->new_pc;
	//TODO : check the carry change
	/* Change the carry */
	proc->carry = !proc->reg[proc->instr->args[0].data % 256];
}
