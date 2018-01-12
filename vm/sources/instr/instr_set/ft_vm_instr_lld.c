/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_lld.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:45:58 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/11 21:25:25 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

void				ft_vm_instr_lld(t_vm *vm, t_process *proc, t_instr *instr)
{
	if (instr->args[0].type == T_IND)
	{
		instr->args[0].data =
			proc->pc - vm->arena[0] + instr->args[0].data;
	}
	/* Load the value in a register */
	proc->reg[instr->args[1].data] =
		ft_instruction_get_data(IND_SIZE,
			&vm->arena[0][MOD(instr->args[0].data)],
			&vm->arena[0][0],
			IS_BIG_ENDIAN);
	/* Display additional informations */
	DISP_OPT ?  ft_vm_display_ld_lld(vm, proc, instr) : 0;
	/* Fetch the next instruction */
	proc->pc = instr->new_pc;
	/* Write in the logfile */
	if (LOG_OPT)
		ft_vm_log_ld_lld(vm, proc);
	/* Change the carry */
	proc->carry = !instr->args[0].data;
}
