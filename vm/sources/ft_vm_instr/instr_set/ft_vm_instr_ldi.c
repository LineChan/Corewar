/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_ldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:38:20 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/27 17:55:39 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void				ft_vm_instr_ldi(t_vm *vm, t_process *proc,
									unsigned char *ptr,
									const unsigned int )
{
	int					i;
	unsigned int		value_to_load;
	unsigned char		*ptr;
	extern uint8_t		g_direct_jump_table_from_instr[17];

	/* Set a pointer at the beginning of the arguments */
	ptr = vm->pc + 2;
	value_to_load = 0;
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
			value_to_load += proc->reg[*ptr];
		}
		else if (proc->op->arg_types[i] == T_IND)
		{
			value_to_load += vm->arena[0][MOD((vm->pc - vm->arena[0] +
				(ft_instruction_get_data(2, ptr) % IDX_MOD)))];
		}
		else if (proc->op->arg_types[i] == T_DIR)
		{
			value_to_load +=
				ft_instruction_get_data(
				g_direct_jump_table_from_instr[proc->op->numero], ptr);
		}
		ptr += proc->jump[i];
		++i;
	}
	/* Load the value in a register */
	if (!IS_REG(*ptr))
	{
		ft_vm_instr_fail(proc, CARRY_CHANGE);
		return ;
	}
	proc->reg[*ptr] = value_to_load % IDX;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
	/* Write in a log file */
	LOG_OPT ? ft_vm_log_ldi(vm, proc, ptr, value_to_load) : 0;
	/* Change the carry */
	proc->carry ^= proc->carry;
}
