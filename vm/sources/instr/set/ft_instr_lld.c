/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_lld.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:42:34 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/27 16:13:06 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void			ft_instr_lld(t_vm *vm, t_proc *proc)
{
	/* Compute index = PC + argument */
	if (proc->instr->args[0].type == T_IND)
	{
		proc->instr->args[0].data =
		ft_arena_get_int32(vm, LOOP(proc->pc + proc->instr->args[0].data));
	}
	/* Load the value in a register from arena[PC + index] */
	proc->reg[proc->instr->args[1].data] = proc->instr->args[0].data;
	/* Display additional informations */
	if (DISPLAY_4)
		ft_display_ld_lld(proc);
	/* Carry the carry */
	proc->carry = !proc->instr->args[0].data;
}
