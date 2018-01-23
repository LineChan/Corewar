/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_st.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:32:20 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/21 15:13:29 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

void			ft_instr_st(t_vm *vm, t_proc *proc)
{
	/* Display additional informations */
	if (DISPLAY_4)
		ft_display_st(proc);
	if (proc->instr->args[1].type == T_REG)
	{
		/* Store the value in a register */
		proc->reg[proc->instr->args[1].data] = proc->reg[proc->instr->args[0].data];
	}
	else
	{
		/* Convert the register to little endian */
		proc->instr->args[0].data =
			ft_endian_convert_int32(proc->reg[proc->instr->args[0].data]);
		/* Store the value in the arena at index = PC + (arg % IDX_MOD) */
		ft_instr_st_data(REG_SIZE,
			&vm->arena[0][MOD(proc->pc + (proc->instr->args[1].data % IDX_MOD))],
			&proc->instr->args[0].data, vm);
	}
	/* Display additional informations */
	if (DISPLAY_16)
		ft_display_pc(vm, proc);
}
