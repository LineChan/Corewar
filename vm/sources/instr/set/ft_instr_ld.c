/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_ld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:07:56 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/27 16:38:24 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void			ft_instr_ld(t_vm *vm, t_proc *proc)
{
	if (proc->instr->args[0].type == T_IND)
	{
		proc->instr->args[0].data =
			ft_arena_get_int32(vm, proc->pc + (proc->instr->args[0].data % IDX_MOD));
	}
	/* Load the value in a resgister */
	proc->reg[proc->instr->args[1].data] = proc->instr->args[0].data;
	/* Display additionnal informations */
	if (DISPLAY_4)
		ft_display_ld_lld(proc);
	/* Change the carry */
	proc->carry = !proc->reg[proc->instr->args[1].data];
}
