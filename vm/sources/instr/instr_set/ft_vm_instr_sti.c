/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_sti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:57:32 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/11 21:26:41 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "endian.h"
#include "ft_instruction.h"

//TODO : lib
#include "ft_printf.h"
void                ft_vm_instr_sti(t_vm *vm, t_process *proc, t_instr *instr)
{
	int			i;

	i = 1;
	/* Convert arguments */
	while (i < instr->op->nb_args)
	{
		if (instr->args[i].type == T_REG)
		{
			if (!REG_IS_VALID(instr->args[i].data))
			{

				/* Write in a logfile */
				// TODO : logfile
				if (DISPLAY_16)
					ft_vm_display_pc(vm, proc, instr);
				/* Fetch the next instruction */
				proc->pc = instr->new_pc;
				return ;
			}
			instr->args[i].data = proc->reg[instr->args[i].data];
		}
		else if (instr->args[i].type == T_IND)
		{
			instr->args[i].data =
				ft_instruction_get_data(REG_SIZE,
					&vm->arena[0][MOD(proc->pc - vm->arena[0]
						+ (instr->args[i].data % IDX_MOD))],
					&vm->arena[0][0],
					IS_BIG_ENDIAN);
		}
		++i;
	}
	/* Convert the register to little endian */
	if (!REG_IS_VALID(instr->args[0].data))
	{
		// TODO : logfile
		if (DISPLAY_16)
			ft_vm_display_pc(vm, proc, instr);
		proc->pc = instr->new_pc;
	}
	else
	{
		/* Display additional informations */
		if (DISPLAY_4)
			ft_vm_display_sti(vm, proc, instr);
		/* Write in the log file */
		ft_vm_log_sti(vm, proc);
		instr->args[0].data = ft_endian_convert_int32(proc->reg[instr->args[0].data]);
		/* Store the value in the arena */
		ft_vm_instr_st_data(vm,
							&vm->arena[0][MOD(proc->pc - vm->arena[0]
							+ (instr->args[1].data + instr->args[2].data) % IDX_MOD)],
							&instr->args[0].data,
							REG_SIZE);
		/* Display additional informations */
		if (DISPLAY_16)
			ft_vm_display_pc(vm, proc, instr);
		/* Fetch the next instruction */
		proc->pc = instr->new_pc;
	}
}
