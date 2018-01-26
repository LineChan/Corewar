/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_and_or_xor_routine.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:33:26 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/26 13:52:41 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_printf.h"

void			ft_instr_and_or_xor_routine(t_vm *vm, t_proc *proc)
{
	int		i;

	i = 0;
	/* Parse arguments */
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
				proc->pc + (proc->instr->args[i].data % IDX_MOD));
		}
		++i;
	}
	/* Display additional informations */
	if (DISPLAY_4)
	{
		ft_printf("P %4d | %s %d %d r%d\n",
			-proc->proc_nb,
			proc->instr->op->name,
			proc->instr->args[0].data,
			proc->instr->args[1].data,
			proc->instr->args[2].data);
	}
	if (DISPLAY_16)
		ft_display_pc(vm, proc);
}
