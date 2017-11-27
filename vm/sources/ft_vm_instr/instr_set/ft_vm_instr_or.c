/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_or.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:31:29 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/27 17:56:42 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void				ft_vm_instr_or(t_vm *vm, t_process *proc)
{
	int					i;
	unsigned int		or[2];
	unsigned char		*ptr;
	extern uint8_t		g_direct_jump_table_from_instr[17];
	extern t_op			g_op_tab[17];

	/* Set up a pointer a the beginning of the arguments */
	ptr = proc->pc + 2;
	i = 0;
	/* Read arguments */
	while (i < (proc->op->arg_types[i] - 1))
	{
		if (proc->op->arg_types[i] == T_REG)
		{
			if (!IS_REG(*ptr))
			{
				ft_vm_instr_fail(proc, CARRY_CHANGE);
				return ;
			}
			or[i] = proc->reg[*ptr];
		}
		else if (proc->op->arg_types[i] == T_IND)
		{
			or[i] = vm->arena[0][MOD((proc->pc - vm->arena[0] +
				(ft_instruction_get_data(2, ptr) % IDX_MOD)))];
		}
		else
			or[i] = ft_instruction_get_data(g_direct_jump_table_from_instr[proc->op->numero], ptr);
		ptr += proc->jump[i];
		++i;
	}
	if (!IS_REG(*ptr))
	{
		ft_vm_instr_fail(proc, CARRY_CHANGE);
		return ;
	}
	/* Compute the result and load it in a register */
	proc->reg[*ptr] = or[0] | or[1];
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
	/* Write in the log file */
	LOG_OPT ? ft_vm_log_or(vm, proc, ptr, or) : 0;
	/* Change the carry */
	proc->carry ^= proc->carry;
}
