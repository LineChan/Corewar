/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 23:47:39 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/27 17:56:56 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : libs
#include "ft_printf.h"
void			ft_vm_instr_sub(t_vm *vm, t_process *proc)
{
	int				i;
	unsigned int	sub[3];
	unsigned char	*ptr;
	extern uint8_t	g_direct_jump_table_from_instr[17];
	extern t_op		g_op_tab[17];

	ft_printf("instr_sub : current_cycle : %d\n");
	i = 0;
	/*  Set a pointer at the beginning of the arguments */
	ptr = proc->pc + 2;
	/* Read arguments */
	while (i < proc->op->nb_args)
	{
		sub[i] = *ptr;
		++ptr;
		++i;
	}
	if (!(IS_REG(sub[0]) && IS_REG(sub[1]) && IS_REG(sub[2])))
	{
		ft_vm_instr_fail(proc, CARRY_CHANGE);
		return ;
	}
	/* Compute the value and load it in a register */
	proc->reg[sub[2]] = MOD((proc->reg[sub[0]] - proc->reg[sub[1]]));
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
	/* Write in the log file */
	LOG_OPT ? ft_vm_log_sub(vm, proc, sub) : 0;
	/* Change the carry */
	proc->carry ^= proc->carry;
}
