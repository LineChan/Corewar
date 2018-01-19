/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_ldi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:30:02 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/19 13:46:11 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

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
				ft_instr_get_data(REG_SIZE,
				&vm->arena[0][proc->pc + (proc->instr->args[i].data % IDX_MOD)],
				IS_BIG_ENDIAN);
		}
		++i;
	}
	/* Load the value in a register */
	proc->reg[proc->instr->args[2].data] = ft_instr_get_data(REG_SIZE,
				&vm->arena[0][MOD(proc->pc + (proc->instr->args[0].data + proc->instr->args[1].data) % IDX_MOD)],
				IS_BIG_ENDIAN);
	/* Display additional informations */
	if (DISP_OPT)
		ft_display_ldi(vm, proc);
	/* Change the carry */
	proc->carry = !proc->reg[proc->instr->args[2].data];
}
