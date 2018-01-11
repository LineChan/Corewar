/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_ldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:38:20 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/11 00:07:06 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

void				ft_vm_instr_ldi(t_vm *vm, t_process *proc, t_instr *instr)
{
	int			i;

	i = 0;
	while (i < (instr->op->nb_args - 1))
	{
		if (instr->args[i].type == REG_CODE)
			instr->args[i].data = proc->reg[instr->args[i].data];
		else if (instr->args[i].type == IND_CODE)
		{
			instr->args[i].data =
				ft_instruction_get_data(REG_SIZE,
				&vm->arena[0][MOD(proc->pc -
					vm->arena[0] + (instr->args[i].data % IDX_MOD))],
				&vm->arena[0][0],
				IS_BIG_ENDIAN);
		}
		++i;
	}
	/* Load the value in a register */
	proc->reg[instr->args[2].data] = ft_instruction_get_data(REG_SIZE,
			&vm->arena[0][MOD(proc->pc - vm->arena[0] + (instr->args[0].data + instr->args[1].data) % IDX_MOD)],
			&vm->arena[0][0],
			IS_BIG_ENDIAN);
	/*Display additional informations */
	if (DISP_OPT)
		ft_vm_display_ldi(vm, proc, instr);
	/* Write in a log file */
	//TODO ; logfile
	/* Fetch the next instruction */
	proc->pc = instr->new_pc;
	/* Change the carry */
	proc->carry = !proc->reg[instr->args[2].data];
}
