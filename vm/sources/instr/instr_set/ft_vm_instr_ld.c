/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_ld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:29:01 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 12:48:00 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "endian.h"
#include "ft_instruction.h"

void			ft_vm_instr_ld(t_vm *vm, t_process *proc)
{
	if (proc->instr->args[0].type == T_IND)
	{
		proc->instr->args[0].data = ft_instruction_get_data(REG_SIZE,
				&vm->arena[0][proc->pc - vm->arena[0] +
				(proc->instr->args[0].data % IDX_MOD)],
				&vm->arena[0][0],
				IS_BIG_ENDIAN);
	}
	/* Load the value in a register */
	proc->reg[proc->instr->args[1].data] = proc->instr->args[0].data;
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
	proc->carry = !proc->reg[proc->instr->args[1].data];
}
