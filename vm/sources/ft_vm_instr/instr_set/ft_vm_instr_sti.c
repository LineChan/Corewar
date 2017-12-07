/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_sti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:57:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/07 16:26:03 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

//TODO: libs
#include "ft_printf.h"
void                ft_vm_instr_sti(t_vm *vm, t_process *proc)
{
	int					i;
	int					address[2];
	unsigned char		*ptr;
	extern uint8_t		g_direct_jump_table_from_instr[17];

	/* Set a pointer at the beginning of the arguments */
	ptr = proc->pc + 2;
	/* Read arguments */
	if (!IS_REG(*ptr))
	{
		ft_vm_instr_fail(vm,
			proc, 2 + proc->jump[0] + proc->jump[1] + proc->jump[2],
			!CARRY_CHANGE);
		return ;
	}
	ptr += proc->jump[0];
	i = 1;
	while (i < proc->op->nb_args)
	{
		if (proc->op->arg_types[i] == T_REG)
		{
			if (!IS_REG(*ptr))
			{
				ft_vm_instr_fail(vm,
					proc, 2 + proc->jump[0] + proc->jump[1] + proc->jump[2],
					!CARRY_CHANGE);
				return ;
			}
			address[i - 1] = proc->reg[*ptr];
		}
		else if (proc->op->arg_types[i] == T_DIR)
			address[i - 1] = ft_instruction_get_data(g_direct_jump_table_from_instr[proc->op->numero], ptr);
		else if (proc->op->arg_types[i] == T_IND)
			address[i - 1] = ft_instruction_get_data(2, ptr);
		ptr += proc->jump[i];
		++i;
	}
	/* Display additional information */
	DISPLAY_4 ? ft_vm_display_sti(vm, proc, address) : 0;
	/* Store the value in the arena */
	if (proc->op->arg_types[1] == T_IND)
	{
		ft_memcpy((void *)&vm->arena[0][MOD(proc->pc - vm->arena[0] + (ft_instruction_get_data(2, &vm->arena[0][address[0]]) + address[1]) % IDX_MOD)], (void *)&proc->reg[*(proc->pc + 2)], REG_SIZE);
	}
	else
	{
		ft_memcpy((void *)&vm->arena[0][MOD(proc->pc - vm->arena[0] + (address[0] + address[1]) % IDX_MOD)], (void *)&proc->reg[*(proc->pc + 2)], REG_SIZE);
	}
	/* Display additional informations */
	DISPLAY_16 ? ft_vm_display_pc(vm, proc, 2 + proc->jump[0] + proc->jump[1] + proc->jump[2]) : 0;
	/* Write in a logfile */
	LOG_OPT ? ft_vm_log_sti(vm, proc, address) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
