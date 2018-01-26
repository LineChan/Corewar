/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_lldi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:48:49 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/25 21:15:13 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

#include "ft_printf.h"
void			ft_instr_lldi(t_vm *vm, t_proc *proc)
{
	int		i;

	i = 0;
	/* Read arguments */
	while (i < (proc->instr->op->nb_args - 1))
	{
		/* Compute index = PC + argument */
		if (proc->instr->args[i].type == T_REG)
		{
			//if (REG_IS_VALID(proc->instr->args[i].data))
				proc->instr->args[i].data = proc->reg[proc->instr->args[i].data];
				// Can be removed ?
				#if 0
			else
			{
				return ;
			}
			#endif
		}
		else if (proc->instr->args[i].type == T_IND)
		{
			/* Get index with PC + argument */
			proc->instr->args[i].data =
				ft_instr_get_data(vm, REG_SIZE,
					&vm->arena[0][MOD(proc->pc + proc->instr->args[i].data)],
					IS_BIG_ENDIAN);
		}
		++i;
	}
	/* Load the value in a register from arena[PC + index] */
	//if (REG_IS_VALID(proc->instr->args[2].data))
	{
		proc->reg[proc->instr->args[2].data] = ft_instr_get_data(vm, REG_SIZE,
				&vm->arena[0][MOD(proc->pc +
					proc->instr->args[0].data + proc->instr->args[1].data)],
				IS_BIG_ENDIAN);
		/* Change the carry */
		proc->carry = !proc->reg[proc->instr->args[2].data];
	}
	/* Display additional informations */
	if (DISP_OPT)
		ft_display_lldi(vm, proc);
}
