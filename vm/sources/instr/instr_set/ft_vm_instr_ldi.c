/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_ldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:38:20 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 13:03:35 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

void				ft_vm_instr_ldi(t_vm *vm, t_process *proc)
{
	int			i;

	i = 0;
	while (i < (proc->instr->op->nb_args - 1))
	{
		/* Copy the value from the register */
		if (proc->instr->args[i].type == T_REG)
			proc->instr->args[i].data = proc->reg[proc->instr->args[i].data];
		/* Load the value from arena[PC + (index % IDX_MOD)] */
		else if (proc->instr->args[i].type == T_IND)
		{
			proc->instr->args[i].data =
				ft_instruction_get_data(REG_SIZE,
				&vm->arena[0][MOD(proc->pc -
					vm->arena[0] + (proc->instr->args[i].data % IDX_MOD))],
				&vm->arena[0][0],
				IS_BIG_ENDIAN);
		}
		++i;
	}
	/* Load the value in a register */
	proc->reg[proc->instr->args[2].data] = ft_instruction_get_data(REG_SIZE,
			&vm->arena[0][MOD(proc->pc - vm->arena[0] +
				(proc->instr->args[0].data + proc->instr->args[1].data) % IDX_MOD)],
			&vm->arena[0][0],
			IS_BIG_ENDIAN);
	/*Display additional informations */
	if (DISP_OPT)
		ft_vm_display_ldi(vm, proc);
	/* Write in a log file */
	//TODO ; logfile
	/* Fetch the next instruction */
	proc->pc = proc->instr->new_pc;
	/* Change the carry */
	proc->carry = !proc->reg[proc->instr->args[2].data];
}
