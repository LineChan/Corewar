/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_lld.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:45:58 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/29 15:37:34 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void				ft_vm_instr_lld(t_vm *vm, t_process *proc)
{
	extern uint8_t 		g_direct_jump_table_from_instr[17];
	int					value_to_load;
	unsigned char		*ptr;

	/* Set up a pointer at the beginning of the arguments */
	ptr = proc->pc + 2;
	/* Read arguments */
	if (proc->op->arg_types[0] == T_DIR)
		value_to_load = ft_instruction_get_data(g_direct_jump_table_from_instr[proc->op->numero], ptr);
	else
		value_to_load = proc->pc - vm->arena[0] + (ft_instruction_get_data(2, ptr) % IDX_MOD);
	ptr += proc->jump[0];
	/* Load the value in a register */
	if (!IS_REG(*ptr))
	{
		ft_vm_instr_fail(proc, CARRY_CHANGE);
		return ;
	}
	/* Load the value in a register */
	proc->reg[*ptr] = MOD(value_to_load);
	/* Write in a log file */
	LOG_OPT ? ft_vm_log_lld(vm, proc, ptr, value_to_load) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1];
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(proc);
	/* Change the carry */
	proc->carry ^= proc->carry;
}
