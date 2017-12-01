/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_lldi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:11:20 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/30 15:31:58 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : libs
#include <libc.h>
#include "ft_printf.h"
#include "ft_log.h"
void			ft_vm_instr_lldi(t_vm *vm, t_process *proc)
{
	int					i;
	int					sum;
	unsigned char		*ptr;
	extern uint8_t		g_direct_jump_table_from_instr[17];

	/* Set up a pointer at the beginning of the arguments */
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
				ft_vm_instr_fail(proc, CARRY_CHANGE);
				return ;
			}
			if (!i)
				sum += proc->pc - vm->arena[0] + proc->reg[*ptr];
			else
				sum += proc->reg[*ptr];
		}
		else if (proc->op->arg_types[i] == T_IND)
		{

			ft_log("IND get_data : %d\n", ft_instruction_get_data(2, ptr));
			sum += ft_instruction_get_data(2, ptr);
		}
		else
		{
			#if 0
			if (!i)
				sum += proc->pc - vm->arena[0] +
				ft_instruction_get_data(
				g_direct_jump_table_from_instr[proc->op->numero], ptr);
			else
			#endif
			ft_log("DIR get_data : %d\n", ft_instruction_get_data(g_direct_jump_table_from_instr[proc->op->numero], ptr));
				sum +=
				ft_instruction_get_data(
				g_direct_jump_table_from_instr[proc->op->numero], ptr);
		}
		ptr += proc->jump[i];
		++i;
	}
	if (!IS_REG(*ptr))
	{
		ft_vm_instr_fail(proc, CARRY_CHANGE);
		return ;
	}
	/* Load the value in a register */
	proc->reg[*ptr] = vm->arena[0][MOD(sum)];
	/* Write in a log file */
	LOG_OPT ? ft_vm_log_lldi(vm, proc, ptr, sum) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(proc);
	/* Change the carry */
	proc->carry ^= proc->carry;
}
