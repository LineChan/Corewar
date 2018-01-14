/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_sti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:57:32 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 12:37:31 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "endian.h"
#include "ft_instruction.h"

void                ft_vm_instr_sti(t_vm *vm, t_process *proc)
{
	int			i;

	i = 1;
	/* Read arguments */
	while (i < proc->instr->op->nb_args)
	{
		/* Get the value from the register */
		if (proc->instr->args[i].type == T_REG)
		{
			#if 0
			if (!REG_IS_VALID(instr->args[i].data))
			{

				/* Write in a logfile */
				// TODO : logfile
				if (DISPLAY_16)
					ft_vm_display_pc(vm, proc);
				/* Fetch the next instruction */
				proc->pc = instr->new_pc;
				return ;
			}
			#endif
			proc->instr->args[i].data = proc->reg[proc->instr->args[i].data];
		}
		/* Get the value from index = PC + (arg % IDX_MOD) */
		else if (proc->instr->args[i].type == T_IND)
		{
			proc->instr->args[i].data =
				ft_instruction_get_data(REG_SIZE,
					&vm->arena[0][MOD(proc->pc - vm->arena[0]
						+ (proc->instr->args[i].data % IDX_MOD))],
					&vm->arena[0][0],
					IS_BIG_ENDIAN);
		}
		++i;
	}
	#if 0
	if (!REG_IS_VALID(instr->args[0].data))
	{
		// TODO : logfile
		if (DISPLAY_16)
			ft_vm_display_pc(vm, proc, instr);
		proc->pc = instr->new_pc;
	}
	else
	#endif
	{
		/* Display additional informations */
		if (DISPLAY_4)
			ft_vm_display_sti(vm, proc);
			#if 0
		/* Write in the log file */
		ft_vm_log_sti(vm, proc);
		#endif
		/* Convert the register to little endian */
		proc->instr->args[0].data =
			ft_endian_convert_int32(proc->reg[proc->instr->args[0].data]);
		/* Store the value in the arena */
		ft_vm_instr_st_data(vm,
							&vm->arena[0][MOD(proc->pc - vm->arena[0]
							+ (proc->instr->args[1].data + proc->instr->args[2].data) % IDX_MOD)],
							&proc->instr->args[0].data,
							REG_SIZE);
		/* Display additional informations */
		if (DISPLAY_16)
			ft_vm_display_pc(vm, proc);
		/* Fetch the next instruction */
		proc->pc = proc->instr->new_pc;
	}
}
