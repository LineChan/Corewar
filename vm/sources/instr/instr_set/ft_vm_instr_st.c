/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_st.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:40:55 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 12:47:39 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

void			ft_vm_instr_st(t_vm *vm, t_process *proc)
{
	/* Display additional informations */
	if (DISPLAY_4)
		ft_vm_display_st(proc);
	if (proc->instr->args[1].type == T_REG)
	{
		/* Store the value in a register */
		proc->reg[proc->instr->args[1].data] = proc->reg[proc->instr->args[0].data];
	}
	else
	{
		/* Convert the register to little endian */
		proc->instr->args[0].data =
			ft_endian_convert_int32(proc->reg[proc->instr->args[0].data]);
		/* Store the value in the arena at index = PC + (arg % IDX_MOD)*/
		ft_vm_instr_st_data(vm,
							&vm->arena[0][MOD(proc->pc - vm->arena[0]
								+ (proc->instr->args[1].data % IDX_MOD))],
							&proc->instr->args[0].data,
							REG_SIZE);
	}
	/* Display additional informations */
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc);
	/* Write in the log file */
	//TODO : logfile
	/* Fetch the next instruction */
	proc->pc = proc->instr->new_pc;
}
