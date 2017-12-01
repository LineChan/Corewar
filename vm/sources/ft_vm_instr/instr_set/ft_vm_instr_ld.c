/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_ld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:29:01 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/30 12:58:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : libs
#include <libc.h>
#include "ft_printf.h"
#include "ft_string.h"

void			ft_vm_instr_ld(t_vm *vm, t_process *proc)
{
	int					address;
	unsigned char		*ptr;
	extern uint8_t		g_direct_jump_table_from_instr[17];

	/* Set a pointer at the beginnig of the arguments */
	ptr = proc->pc + 2;
	/* Read arguments */
	if (proc->op->arg_types[0] == T_DIR)
	{
		address =
		ft_instruction_get_data(g_direct_jump_table_from_instr[proc->op->numero],
		ptr);
	}
	else
	{
		address = proc->pc - vm->arena[0] +
		(ft_instruction_get_data(2, ptr) % IDX_MOD);
	}
	ptr += proc->jump[0];
	if (!IS_REG(*ptr))
	{
		ft_vm_instr_fail(proc, CARRY_CHANGE);
		return ;
	}
	/* Load the value in a register */
	proc->reg[*ptr] = ft_instruction_get_data(REG_SIZE, &vm->arena[0][MOD(address)]);
	/* Write in the log file */
	LOG_OPT ? ft_vm_log_ld(vm, proc, ptr, address) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1];
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(proc);
	/* Change the carry */
	proc->carry ^= proc->carry;
}
