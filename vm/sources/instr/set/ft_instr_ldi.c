/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_ldi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:30:02 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/27 16:41:55 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_printf.h"

void			ft_instr_ldi(t_vm *vm, t_proc *proc)
{
	int		i;

	i = 0;
	while (i < (proc->instr->op->nb_args - 1))
	{
		/* Copy the value from the register */
		if (proc->instr->args[i].type == T_REG)
				proc->instr->args[i].data = proc->reg[proc->instr->args[i].data];
		/* Load the value from arena[PC + (index % IDX_MOD)] */
		else if (proc->instr->args[i].type == T_IND)
		{
			proc->instr->args[i].data =
				ft_arena_get_int32(vm,
					LOOP(proc->pc + (proc->instr->args[i].data % IDX_MOD)));
		}
		++i;
	}
	/* Load the value in a register */
	proc->reg[proc->instr->args[2].data] = ft_arena_get_int32(vm,
			LOOP(proc->pc + (proc->instr->args[0].data
				+ proc->instr->args[1].data) % IDX_MOD));
	/* Display additional informations */
if (DISPLAY_4)
		ft_display_ldi(proc);
}
