/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_ld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:29:01 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/20 16:06:00 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

void			ft_vm_instr_ld(t_vm *vm, t_process *proc, t_instr *instr)
{
	if (instr->args[0].type == IND_CODE)
	{
		instr->args[0].data =
			proc->pc - vm->arena[0] + (instr->args[0].data % IDX_MOD);
		/* Load the value in a register */
		proc->reg[instr->args[1].data] =
			ft_instruction_get_data(REG_SIZE,
				&vm->arena[0][MOD(instr->args[0].data)],
				&vm->arena[0][0],
				IS_BIG_ENDIAN);
	}
	else
		proc->reg[instr->args[1].data] = instr->args[0].data;
	/* Display additional informations */
	DISP_OPT ?  ft_vm_display_ld_lld(vm, proc, instr) : 0;
	/* Fetch the next instruction */
	proc->pc = instr->new_pc;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
	/* Change the carry */
	if (!instr->args[0].data)
		proc->carry = 1;
	else
		proc->carry = 0;
}
