/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_and_or_xor_routine.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:37:40 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 12:56:32 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "endian.h"
#include "ft_instruction.h"

void			ft_vm_instr_and_or_xor_routine(t_vm *vm, t_process *proc)
{
	int			i;

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
				ft_instruction_get_data(REG_SIZE,
					&vm->arena[0][MOD(proc->pc - vm->arena[0] + (proc->instr->args[i].data % IDX_MOD))],
					&vm->arena[0][0],
					IS_BIG_ENDIAN);
		}
		++i;
	}
	/* Display additional informations */
	if (DISPLAY_4)
	{
		ft_printf("P %4d | %s %d %d r%d\n",
			-proc->process_nb,
			proc->instr->op->name,
			proc->instr->args[0].data,
			proc->instr->args[1].data,
			proc->instr->args[2].data);
	}
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc);
}
