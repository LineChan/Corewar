/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_and.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:26:51 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/27 00:51:30 by mvillemi         ###   ########.fr       */
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
	ptr = vm->pc + 2;
	i = 0;
	/* Read arguments */
	while (i < (proc->nb_args - 1))
	{
		if (proc->arg_types[i] == T_REG)
		{
			if (!IS_REG(*ptr))
			{
				ft_vm_instr_fail(proc, CARRY_CHANGE);
				return ;
			}
			and[i] = proc->reg[*ptr];
		}
		else if (proc->arg_types[i] == T_IND)
			add[i] = vm->arena[0][MOD((proc->vm - arena[0] + (ft_instruction_get_data(2, ptr) % IDX_MOD)))];
		else
			add[i] = ft_instruction_get_data(g_direct_jump_table_from_instr[proc->op->numero], ptr);
		ptr += proc->jump[0];
		++i;
		/* Add arguments and store the result in a register */
		if (!IS_REG(*ptr))
		{
			ft_vm_instr_fail(proc, CARRY_CHANGE);
			return ;
		}
		proc->reg[*ptr] = and[0] & and[1];
		/* Fetch the next instruction */
		proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
		/* Write in the log file */
		//LOG_OPT ? ft_vm_log_and(proc, ptr, and) : 0;
		/* 
	}
}
