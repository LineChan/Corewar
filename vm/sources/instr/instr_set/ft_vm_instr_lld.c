/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_lld.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:45:58 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 13:02:07 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

void				ft_vm_instr_lld(t_vm *vm, t_process *proc)
{
	/* Compute index = PC + argument */
	if (proc->instr->args[0].type == T_IND)
	{
		proc->instr->args[0].data =
			proc->pc - vm->arena[0] + proc->instr->args[0].data;
	}
	/* Load the value in a register from arena[PC + index] */
	proc->reg[proc->instr->args[1].data] =
		ft_instruction_get_data(IND_SIZE,
			&vm->arena[0][MOD(proc->instr->args[0].data)],
			&vm->arena[0][0],
			IS_BIG_ENDIAN);
	/* Display additional informations */
	if (DISP_OPT)
		ft_vm_display_ld_lld(vm, proc);
	/* Fetch the next instruction */
	proc->pc = proc->instr->new_pc;
	#if 0
	/* Write in the logfile */
	if (LOG_OPT)
		ft_vm_log_ld_lld(vm, proc);
	#endif
	/* Change the carry */
	proc->carry = !proc->instr->args[0].data;
}
