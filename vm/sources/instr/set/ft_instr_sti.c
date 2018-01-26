/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_sti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:53:14 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/26 16:47:35 by mvillemi         ###   ########.fr       */
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
			proc->instr->args[i].data = proc->reg[proc->instr->args[i].data];
		/* Get the value from index = PC + (arg % IDX_MOD) */
		else if (proc->instr->args[i].type == T_IND)
		{
			proc->instr->args[i].data =
				ft_arena_get_int32(vm,
				proc->pc + (proc->instr->args[i].data % IDX_MOD));
		}
		++i;
	}
	if (DISPLAY_4)
		ft_display_sti(proc);
	ft_arena_set_int32(vm,
		proc->pc + (proc->instr->args[1].data + proc->instr->args[2].data)% IDX_MOD,
		proc->reg[proc->instr->args[0].data]);
	/* Display additional informations */
	if (DISPLAY_16)
		ft_display_pc(vm, proc);
}
