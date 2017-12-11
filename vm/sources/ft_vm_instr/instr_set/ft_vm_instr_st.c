/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_st.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:40:55 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/11 17:38:20 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

//TODO : lisb
#include "ft_printf.h"


void			ft_vm_instr_st(t_vm *vm, t_process *proc)
{
	extern uint8_t		g_direct_jump_table_from_instr[17];

	/* Read arguments */
	if (!IS_REG(*(proc->pc + 2)))
	{
		ft_vm_instr_fail(vm, proc, 2 + proc->jump[0] + proc->jump[1],
		!CARRY_CHANGE);
		return ;
	}
	if (proc->op->arg_types[1] == T_REG)
	{
		if (!IS_REG(*(proc->pc + 2)))
		{
			ft_vm_instr_fail(vm, proc, 2 + proc->jump[0] + proc->jump[1],
				!CARRY_CHANGE);
			return ;
		}
		/* Display additional informations */
		DISPLAY_4 ? ft_vm_display_st(vm, proc) : 0;
		/* Store the value in a register */
		proc->reg[*(proc->pc + 3)] = proc->reg[*(proc->pc + 2)];
	}
	else
	{

		/* Display additional informations */
		DISPLAY_4 ? ft_vm_display_st(vm, proc) : 0;
		/* Store the value in the arena */
		#if 0
		ft_memcpy((void *)&vm->arena[0][(MOD(proc->pc - vm->arena[0] + (ft_vm_instr_get_data(2, proc->pc + 3, vm) % IDX_MOD)))],
				(void *)&proc->reg[*(proc->pc + 2)], REG_SIZE);
		#endif
		ft_vm_instr_st_data(vm, &vm->arena[0][(MOD(proc->pc - vm->arena[0] + (ft_vm_instr_get_data(2, proc->pc + 3, vm) % IDX_MOD)))], &proc->reg[*(proc->pc + 2)]);
	}
	/* Display additional informations */
	DISPLAY_16 ? ft_vm_display_pc(vm, proc, 2 + proc->jump[0] + proc->jump[1]) : 0;
	/* Write in the log file */
	LOG_OPT ? ft_vm_log_st(vm, proc) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1];
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
