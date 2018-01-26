/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_sti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:53:14 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/25 21:03:41 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

#include "ft_printf.h"
void			ft_instr_sti(t_vm *vm, t_proc *proc)
{
	int			i;

	i = 1;
	/* Read arguments */
	while (i < proc->instr->op->nb_args)
	{
		/* Get the value from a register */
		if (proc->instr->args[i].type == T_REG)
		{
			//if (REG_IS_VALID(proc->instr->args[i].data))
				proc->instr->args[i].data = proc->reg[proc->instr->args[i].data];
				/*
			else
				return ;
				*/
		}
		/* Get the value from index = PC + (arg % IDX_MOD) */
		else if (proc->instr->args[i].type == T_IND)
		{
			proc->instr->args[i].data =
				ft_instr_get_data(vm, REG_SIZE,
				&vm->arena[0][proc->pc + (proc->instr->args[i].data % IDX_MOD)],
				IS_BIG_ENDIAN);
		}
		++i;
	}
	if (DISPLAY_4)
		ft_display_sti(proc);
	/* Convert the register to little endian */
	proc->instr->args[0].data =
		ft_endian_convert_int32(proc->reg[proc->instr->args[0].data]);
	/* Store the value in the arena */
	ft_instr_st_data(REG_SIZE,
		&vm->arena[0][MOD(proc->pc + (proc->instr->args[1].data + proc->instr->args[2].data) % IDX_MOD)],
		&proc->instr->args[0].data, vm);
	/* Display additional informations */
	if (DISPLAY_16)
		ft_display_pc(vm, proc);
}
