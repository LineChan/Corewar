/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_ld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:07:56 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/18 18:12:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_instr_ld(t_vm *vm, t_proc *proc)
{
	if (proc->instr->args[0].type == T_IND)
	{
		//proc->instr->args[0].data = ft_instr_get_data()
	}
	/* Load the value in a resgister */
	proc->reg[proc->instr->args[1].data] = proc->instr->args[0].data;
	/* Display additionnal informations */
	if (DISP_OPT)
		ft_display_ld_lld(vm, proc);
	/* Fetch the next instruction */
	proc->pc = proc->instr->new_pc;
	/* Change the carry */
	proc->carry = !proc->reg[proc->instr->args[1].data];
}
