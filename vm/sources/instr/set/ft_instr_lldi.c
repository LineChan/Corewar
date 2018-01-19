/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_lldi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:48:49 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/19 16:12:37 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

void			ft_instr_lldi(t_vm *vm, t_proc *proc)
{
	int		i;

	i = 0;
	/* Read arguments */
	while (i < (proc->instr->op->nb_args - 1))
	{
		/* Compute index = PC + argument */
		if (proc->instr->args[i].type == T_REG)
			proc->instr->args[i].data = proc->reg[proc->instr->args[i].data];
		else if (proc->instr->args[i].type == T_IND)
		{
			/* Get index with PC + argument */
			proc->instr->args[i].data =
				ft_instr_get_data(REG_SIZE,
					&vm->arena[0][MOD(proc->pc + proc->instr->args[i].data)],
					IS_BIG_ENDIAN);
		}
		++i;
	}
	/* Load the value in a register from arena[PC + index] */
	proc->reg[proc->instr->args[2].data] = ft_instr_get_data(REG_SIZE,
			&vm->arena[0][MOD(proc->pc +
				(proc->instr->args[0].data + proc->instr->args[1].data) % IDX_MOD)],
			IS_BIG_ENDIAN);
	/* Display additional informations */
	if (DISP_OPT)
		ft_display_lldi(vm, proc);
	/* Change the carry */
	proc->carry = !proc->instr->args[0].data;
}
