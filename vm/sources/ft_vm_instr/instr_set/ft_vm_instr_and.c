/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_and.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:26:51 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/01 15:42:29 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_vm_instr_and(t_vm *vm, t_process *proc)
{
	int				i;
	unsigned int	and[2];
	unsigned char	*ptr;
	extern uint8_t	g_direct_jump_table_from_instr[17];

	/* Set up a pointer at the beginning of the arguments */
	ptr = proc->pc + 2;
	i = 0;
	/* Read arguments */
	while (i < (proc->op->nb_args - 1))
	{
		if (proc->op->arg_types[i] == T_REG)
		{
			if (!IS_REG(*ptr))
			{
				ft_vm_instr_fail(vm, proc, CARRY_CHANGE);
				return ;
			}
			and[i] = proc->reg[*ptr];
		}
		else if (proc->op->arg_types[i] == T_IND)
			and[i] = vm->arena[0][MOD((proc->pc - vm->arena[0] + (ft_instruction_get_data(2, ptr) % IDX_MOD)))];
		else
			and[i] = ft_instruction_get_data(g_direct_jump_table_from_instr[proc->op->numero], ptr);
		ptr += proc->jump[i];
		++i;
	}
	/* Add arguments and store the result in a register */
	if (!IS_REG(*ptr))
	{
		ft_vm_instr_fail(vm, proc, CARRY_CHANGE);
		return ;
	}
	/* Compute the result and store it in a register */
	proc->reg[*ptr] = and[0] & and[1];
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
	/* Write in the log file */
	LOG_OPT ? ft_vm_log_and(vm, proc, ptr, and) : 0;
	/* Change the carry */
	proc->carry ^= proc->carry;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
