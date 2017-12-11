/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_lld.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:45:58 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/11 18:14:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
//TODO:Libraries
#include "ft_printf.h"
void				ft_vm_instr_lld(t_vm *vm, t_process *proc)
{
	int					address;
	unsigned char		*ptr;
	extern uint8_t 		g_direct_jump_table_from_instr[17];

	/* Set up a pointer at the beginning of the arguments */
	ptr = proc->pc + 2;
	/* Read arguments */
	if (proc->op->arg_types[0] == T_DIR)
	{
		address =
		ft_vm_instr_get_data(g_direct_jump_table_from_instr[proc->op->numero],
		ptr, vm);
	}
	else
	{
		address = (int)(proc->pc - vm->arena[0] + ft_vm_instr_get_data(2, ptr, vm));
		//ft_printf("IND address : %d\n", address);
	}
	ptr += proc->jump[0];
	if (!IS_REG(*ptr))
	{
		ft_vm_instr_fail(vm, proc, 2 + proc->jump[0] + proc->jump[1],
			CARRY_CHANGE);
		return ;
	}
	proc->reg[*ptr] =
		ft_vm_instr_get_data(IND_SIZE, &vm->arena[0][MOD(address)], vm);
	#if 0
	if (proc->op->arg_types[0] == T_DIR)
	{
		/* Load the value in a register */
		proc->reg[*ptr] =
			ft_vm_instr_get_data(IND_SIZE, &vm->arena[0][MOD(address)], vm);
	}
	else
	{
		/* Load the value in a register */
		proc->reg[*ptr] =
			ft_vm_instr_get_data(IND_SIZE, &vm->arena[0][MOD(address)], vm);
	}
	#endif
	/* Display additional informations */
	DISP_OPT ? ft_vm_display_lld(vm, proc, ptr, address) : 0;
	/*
	if (DISP_OPT)
	{
		DISPLAY_16 ? ft_vm_display_pc(vm, proc,
					2 + proc->jump[0] + proc->jump[1]) : 0;
	}
	*/
	/* Write in the log file */
	LOG_OPT ? ft_vm_log_lld(vm, proc, ptr, address) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1];
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
	/* Change the carry */
	proc->carry ^= proc->carry;
}
