/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_xor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:21:54 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/29 00:36:27 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_vm_instr_xor(t_vm *vm, t_process *proc)
{
	int					i;
	unsigned int		xor[2];
	unsigned char		*ptr;
	extern uint8_t		g_direct_jump_table_from_instr[17];

	/* Set a pointer at the beginnin of the arguments */
	ptr = proc->pc + 2;
	i = 0;
	/* Read arguments */
	while (i < (proc->op->nb_args - 1))
	{
		if (proc->op->arg_types[i] == T_REG)
		{
			if (!IS_REG(*ptr))
			{
				ft_vm_instr_fail(proc, CARRY_CHANGE);
				return ;
			}
			xor[i] = proc->reg[*ptr];
		}
		else if (proc->op->arg_types[i] == T_IND)
		{
			xor[i] = vm->arena[0][MOD((proc->pc - vm->arena[0]
				+ (ft_instruction_get_data(2, ptr) % IDX_MOD)))];
		}
		else
		{
			xor[i] = ft_instruction_get_data(
				g_direct_jump_table_from_instr[proc->op->numero], ptr);
		}
		ptr += proc->jump[i];
		++i;
	}
	/* Compute the result and save it in a register */
	if (!IS_REG(*ptr))
	{
		ft_vm_instr_fail(proc, CARRY_CHANGE);
		return ;
	}
	proc->reg[*ptr] = xor[0] ^ xor[1];
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
	/* Write in a log file */
	LOG_OPT ? ft_vm_log_xor(vm, proc, ptr, xor) : 0;
	/* Change the carry */
	proc->carry ^= proc->carry;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(proc);
}
