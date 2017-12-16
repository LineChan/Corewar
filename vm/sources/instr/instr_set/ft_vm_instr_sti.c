/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_sti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:57:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/16 21:19:09 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "endian.h"

//TODO : lib
#include "ft_printf.h"
void                ft_vm_instr_sti(t_vm *vm, t_process *proc, t_instr *instr)
{
	(void)vm;
	(void)proc;
	(void)instr;
	///ft_printf("{red:SEGFAULT}\n");
	int			i;

	i = 1;
	while (i < instr->op->nb_args)
	{
		if (instr->args[i].type == REG_CODE)
			instr->args[i].data = proc->reg[instr->args[i].data];
		else if (instr->args[i].type == IND_CODE)
		{
			#if 1
			instr->args[i].data =
				ft_instruction_get_data(REG_SIZE,
					&vm->arena[0][MOD(proc->pc - vm->arena[0] + (instr->args[i].data % IDX_MOD))],
					&vm->arena[0][0],
					IS_BIG_ENDIAN);
					#endif

			#if 0
			instr->args[i].data =
				ft_instruction_get_data(REG_SIZE,
				&vm->arena[0][proc->pc - vm->arena[0] + ft_instruction_get_data(IND_SIZE,
														&vm->arena[0][MOD(instr->args[i].data)],
														&vm->arena[0][0],
														IS_BIG_ENDIAN)],
				&vm->arena[0][0],
				IS_BIG_ENDIAN);
			#endif
			#if 0
					address[0] = ft_vm_instr_get_data(REG_SIZE,
						&vm->arena[0][proc->pc - vm->arena[0] + address[0]], vm);
			#endif

		}
		#if 0
		else
		{
			instr->args[i].data =
				ft_instruction_get_data(VM_DIR_SIZE,
					&vm->arena[0][MOD(instr->args[i].data)],
					&vm->arena[0][0],
					IS_BIG_ENDIAN);
		}
		#endif
		++i;
	}
	/* Display additional informations */
	if (DISP_OPT)
		ft_vm_display_sti(vm, proc, instr);
	/* Store the value in the arena */
	ft_vm_instr_st_data(&vm->arena[0][MOD(proc->pc - vm->arena[0]
						+ (instr->args[1].data + instr->args[2].data) % IDX_MOD)],
						&proc->reg[instr->args[0].data],
						REG_SIZE);
	/* Write in a logfile */
	// TODO : logfile
	/* Fetch the next instruction */
	proc->pc = instr->new_pc;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);

	#if 0
	int					i;
	int					address[2];
	unsigned char		*ptr;
	extern uint8_t		g_direct_jump_table_from_instr[17];

	(void)instr;
	/* Set a pointer at the beginning of the arguments */
	ptr = proc->pc + 2;
	/* Read arguments */
	if (!IS_REG(*ptr))
	{
		ft_vm_instr_fail(vm,
			proc, 2 + proc->jump[0] + proc->jump[1] + proc->jump[2],
			!CARRY_CHANGE);
		return ;
	}
	ptr += proc->jump[0];
	i = 1;
	while (i < proc->op->nb_args)
	{
		if (proc->op->arg_types[i] == T_REG)
		{
			if (!IS_REG(*ptr))
			{
				ft_vm_instr_fail(vm,
					proc, 2 + proc->jump[0] + proc->jump[1] + proc->jump[2],
					!CARRY_CHANGE);
				return ;
			}
			address[i - 1] = proc->reg[*ptr];
		}
		else if (proc->op->arg_types[i] == T_DIR)
		{
			address[i - 1] =
			ft_vm_instr_get_data(g_direct_jump_table_from_instr[proc->op->numero],
			ptr, vm);

		}
		else if (proc->op->arg_types[i] == T_IND)
			address[i - 1] = ft_vm_instr_get_data(2, ptr, vm);
		ptr += proc->jump[i];
		++i;
	}
	if (proc->op->arg_types[1] == T_IND)
	{
		address[0] = ft_vm_instr_get_data(REG_SIZE,
			&vm->arena[0][proc->pc - vm->arena[0] + address[0]], vm);
	}
	/* Display additional information */
	DISPLAY_4 ? ft_vm_display_sti(vm, proc, address) : 0;
	/* Store the value in the arena */
	ft_memcpy((void *)&vm->arena[0][MOD(proc->pc - vm->arena[0] + (address[0] + address[1]) % IDX_MOD)], (void *)&proc->reg[*(proc->pc + 2)], REG_SIZE);
	/* Display additional informations */
	DISPLAY_16 ? ft_vm_display_pc(vm, proc, 2 + proc->jump[0] + proc->jump[1] + proc->jump[2]) : 0;
	/* Write in a logfile */
	LOG_OPT ? ft_vm_log_sti(vm, proc, address) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
	#endif
}
