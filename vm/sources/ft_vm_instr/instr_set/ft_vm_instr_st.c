/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_st.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:40:55 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/26 22:46:38 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_vm_instr_st(t_vm *vm, t_process *proc)
{
	extern t_op			g_op_tab[17];
	extern uint8_t		g_direct_jump_table_from_instr[17];

	/* Read argumetns */
	if (proc->op->arg_types[1] == T_REG)
	{
		if (!IS_REG(*(proc->pc + 3)) || !IS_REG(*(proc->pc + 2)))
		{
			ft_vm_instr_fail(proc, !CARRY_CHANGE);
			return ;
		}
		/* Store the value in a register */
		proc->reg[*(proc->pc + 3)] = proc->reg[*(proc->pc + 2)];
		/* Write in the log file */
		LOG_OPT ? ft_vm_log_st(vm, proc, T_REG) : 0;
	}
	else
	{
		if (!IS_REG(*(proc->pc + 2)))
		{
			ft_vm_instr_fail(proc, !CARRY_CHANGE);
			return ;
		}
		/* Store a value in a directory */
		vm->arena[0][MOD((proc->pc - vm->arena[0] + (ft_instruction_get_data(2, proc->pc + 3) % IDX_MOD)))] =
			proc->reg[*(proc->pc + 2)];
		/* Write in the log file */
		LOG_OPT ? ft_vm_log_st(vm, proc, T_IND) : 0;
	}
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1];
	/* Add its sleeping time to execution cycle */
	if (IS_INSTR(*proc->pc))
		proc->exec_cycle += g_op_tab[*proc->pc].nb_cycles;
	else
		proc->exec_cycle += 1;
}
