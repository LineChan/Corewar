/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_st.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:40:55 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/13 12:17:55 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

//TODO : lisb
#include "ft_printf.h"


void			ft_vm_instr_st(t_vm *vm, t_process *proc, t_instr *instr)
{
	if (instr->args[1].type == REG_CODE)
	{
		/* Store the value in a register */
		proc->reg[instr->args[1].data] = proc->reg[instr->args[0].data];
	}
	else
	{
		/* Store the value in the arena */
		ft_vm_instr_st_data(&vm->arena[0][MOD(proc->pc - vm->arena[0]
								+ (instr->args[1].data % IDX_MOD))],
							&proc->reg[instr->args[0].data],
							REG_SIZE);
	}
	/* Display additional informations */
	if (DISP_OPT)
		ft_vm_display_st(vm, proc, instr);
	/* Write in the log file */
	//TODO :
	proc->pc = instr->new_pc;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
