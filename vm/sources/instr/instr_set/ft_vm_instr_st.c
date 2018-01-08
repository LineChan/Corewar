/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_st.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:40:55 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/06 22:37:13 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

///TODO : libs
#include "ft_printf.h"
void			ft_vm_instr_st(t_vm *vm, t_process *proc, t_instr *instr)
{
	/* Display additional informations */
	if (DISPLAY_4)
		ft_vm_display_st(proc, instr);
	if (instr->args[1].type == REG_CODE)
	{
		/* Store the value in a register */
		proc->reg[instr->args[1].data] = proc->reg[instr->args[0].data];
	}
	else
	{
		/* Convert the register to little endian */
		instr->args[0].data = ft_endian_convert_int32(proc->reg[instr->args[0].data]);
		/* Store the value in the arena */
		ft_vm_instr_st_data(vm,
							&vm->arena[0][MOD(proc->pc - vm->arena[0]
								+ (instr->args[1].data % IDX_MOD))],
							&instr->args[0].data,
							REG_SIZE);
	}
	/* Display additional informations */
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc, instr);
	/* Write in the log file */
	//TODO :
	/* Fetch the next instruction */
	proc->pc = instr->new_pc;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
	ft_printf("P %d st : next exec->cycle ; %d\n", -proc->process_nb, proc->exec_cycle);
}
