/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_lld.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:42:34 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/25 16:20:14 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

void			ft_instr_lld(t_vm *vm, t_proc *proc)
{
	/* Compute index = PC + argument */
	if (proc->instr->args[0].type == T_IND)
	{
		proc->instr->args[0].data =
		ft_instr_get_data(vm, REG_SIZE,
						&vm->arena[0][MOD(proc->pc + proc->instr->args[0].data)],
						IS_BIG_ENDIAN);
	}
	/* Load the value in a register from arena[PC + index] */
	if (REG_IS_VALID(proc->instr->args[1].data))
	{
		proc->reg[proc->instr->args[1].data] = proc->instr->args[0].data;
		proc->carry = 1;
	}
	else
		return ;
	/* Display additional informations */
	if (DISP_OPT)
		ft_display_ld_lld(vm, proc);
	/* Carry the carry */
	proc->carry = !proc->instr->args[0].data;
}
