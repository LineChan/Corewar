/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 23:16:48 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/27 17:56:05 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_vm_instr_add(t_vm *vm, t_process *proc)
{
	int					i;
	unsigned int		add[3];
	unsigned char		*ptr;
	extern t_op			g_op_tab[17];

	/* Set up a pointer at the beginning of the arguments */
	ptr = proc->pc + 2;
	/* Read arguments */
	i = 0;
	while (i < proc->op->nb_args)
	{
		add[i] = *ptr;
		++ptr;
		++i;
	}
	/* Check if they all are register numbers */
	if (!(IS_REG(add[0]) && IS_REG(add[1]) && IS_REG(add[2])))
	{
		ft_vm_instr_fail(proc, CARRY_CHANGE);
		return ;
	}
	/* Compute the result and load it in a register */
	proc->reg[add[2]] = MOD(proc->reg[add[0]] + proc->reg[add[1]]);
	/* Write in a log file */
	LOG_OPT ? ft_vm_log_add(vm, proc, add) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
	/* Change the carry */
	proc->carry ^= proc->carry;
}
