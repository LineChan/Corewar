/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_lldi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:48:49 by mvillemi          #+#    #+#             */
/*   Updated: 2018/02/02 22:46:25 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void			ft_instr_lldi(t_vm *vm, t_proc *proc)
{
	int		i;

	i = 0;
	/* Read arguments */
	while (i < (proc->instr->op->nb_args - 1))
	{
		/* Get the index from a register */
		if (proc->instr->args[i].type == T_REG)
			proc->instr->args[i].data = proc->reg[proc->instr->args[i].data];
		/* Get the index with PC + argument */
		else if (proc->instr->args[i].type == T_IND)
		{
			proc->instr->args[i].data =
				ft_arena_get_int32(vm, LOOP(proc->pc + proc->instr->args[i].data % IDX_MOD));
		}
		++i;
	}
	/* Load the value in a register from arena[PC + index] */
	proc->reg[proc->instr->args[2].data] =
		ft_arena_get_int32(vm, LOOP(proc->pc + proc->instr->args[0].data
			+ proc->instr->args[1].data));
	/* Change the carry */
	proc->carry = !proc->reg[proc->instr->args[2].data];
	/* Display additional informations */
	if (DISPLAY_4)
		ft_display_lldi(proc);
}
