/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_ldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:38:20 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/05 13:40:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

void				ft_vm_instr_ldi(t_vm *vm, t_process *proc)
{
	int					i;
	unsigned int		sum;
	unsigned char		*ptr;
	extern uint8_t		g_direct_jump_table_from_instr[17];

	/* Set a pointer at the beginning of the arguments */
	ptr = proc->pc + 2;
	sum = 0;
	i = 0;
	/* Read arguments */
	while (i < (proc->op->nb_args - 1))
	{
		if (proc->op->arg_types[i] == T_REG)
		{
			if (!IS_REG(*ptr))
			{
				ft_vm_instr_fail(vm, proc,
					2 + proc->jump[0] + proc->jump[1] + proc->jump[2],
					CARRY_CHANGE);
				return ;
			}
			if (!i)
				sum += proc->pc - vm->arena[0] + (proc->reg[*ptr] % IDX_MOD);
			else
				sum += proc->reg[*ptr];
		}
		else if (proc->op->arg_types[i] == T_IND)
		{
			sum += proc->pc - vm->arena[0] +
				(ft_instruction_get_data(2, ptr) % IDX_MOD);
		}
		else
		{
			if (!i)
				sum += proc->pc - vm->arena[0] +
				ft_instruction_get_data(
				g_direct_jump_table_from_instr[proc->op->numero], ptr) % IDX_MOD;
			else
				sum +=
				ft_instruction_get_data(
				g_direct_jump_table_from_instr[proc->op->numero], ptr);
		}
		ptr += proc->jump[i];
		++i;
	}
	/* Load the value in a register */
	if (!IS_REG(*ptr))
	{
		ft_vm_instr_fail(vm, proc,
			2 + proc->jump[0] + proc->jump[1] + proc->jump[2],
			CARRY_CHANGE);
		return ;
	}
	/* Load the value in a register */
	ft_memcpy((void *)&proc->reg[*ptr],
		(void *)&vm->arena[0][MOD(proc->pc - vm->arena[0] + (sum % IDX_MOD))],
		REG_SIZE);
	/* Display additional informtions */
	if (DISP_OPT)
	{
		//1
		//8
		DISPLAY_16 ? ft_vm_display_pc(vm, proc,
				2 + proc->jump[0] + proc->jump[1] + proc->jump[2]) : 0;
	}
	/* Write in a log file */
	LOG_OPT ? ft_vm_log_ldi(vm, proc, ptr, sum) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
	/* Change the carry */
	proc->carry ^= proc->carry;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
