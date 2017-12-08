/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_ldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:38:20 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/07 23:42:27 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

void				ft_vm_instr_ldi(t_vm *vm, t_process *proc)
{
	int					i;
	int					sum[2];
	unsigned char		*ptr;
	extern uint8_t		g_direct_jump_table_from_instr[17];

	/* Set a pointer at the beginning of the arguments */
	ptr = proc->pc + 2;
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
			sum[i] = proc->reg[*ptr];
		}
		else if (proc->op->arg_types[i] == T_IND)
		{
			sum[i] = ft_vm_instr_get_data(REG_SIZE,
				&vm->arena[0][MOD(proc->pc - vm->arena[0]
				+ (ft_vm_instr_get_data(2, ptr, vm) % IDX_MOD))], vm);
		}
		else
		{
			sum[i] =
			ft_vm_instr_get_data(
			g_direct_jump_table_from_instr[proc->op->numero], ptr, vm);
		}
		ptr += proc->jump[i];
		++i;
	}
	if (!IS_REG(*ptr))
	{
		ft_vm_instr_fail(vm, proc,
			2 + proc->jump[0] + proc->jump[1] + proc->jump[2],
			CARRY_CHANGE);
		return ;
	}
	/*Display additional informations */
	DISPLAY_4 ? ft_vm_display_ldi(vm, proc, sum, ptr) : 0;
	/* Load the value in a register */
	proc->reg[*ptr] = vm->arena[0][MOD(proc->pc - vm->arena[0]
	+ ft_vm_instr_get_data(REG_SIZE, &vm->arena[0][MOD(sum[0] + sum[1])], vm))];
	/*Display additional informations */
	DISPLAY_16 ? ft_vm_display_pc(vm, proc,
		2 + proc->jump[0] + proc->jump[1] + proc->jump[2]) : 0;
	/* Write in a log file */
	LOG_OPT ? ft_vm_log_ldi(vm, proc, ptr, sum) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
	/* Change the carry */
	proc->carry ^= proc->carry;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
