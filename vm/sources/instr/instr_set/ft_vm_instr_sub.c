/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 23:47:39 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/17 14:13:38 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void			ft_vm_instr_sub(t_vm *vm, t_process *proc, t_instr *instr)
{
	/* Compute the value and load it in a register */
	proc->reg[instr->args[2].data] =
		MOD((proc->reg[instr->args[0].data] - proc->reg[instr->args[1].data]));
	/* Display additional informations */
	if (DISP_OPT)
		ft_vm_display_sub(vm, proc, instr);
	/* Write in the log file */
	//TODO : log
	/* Fetch the next instruction */
	proc->pc = instr->new_pc;
	/* Change the carry */
	proc->carry = 0;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);

	#if 0
	int				sub[3];
	unsigned char	*ptr;

	(void)instr;
	ptr = 0;
	if (ft_vm_instr_add_sub_routine(vm, proc, &ptr, sub) == EXIT_FAILURE)
		return ;
	/* Compute the value and load it in a register */
	proc->reg[sub[2]] = MOD((proc->reg[sub[0]] - proc->reg[sub[1]]));
	/* Display additional informations */
	DISP_OPT ? ft_vm_display_sub(vm, proc, sub) : 0;
	/* Write in the log file */
	LOG_OPT ? ft_vm_log_sub(vm, proc, sub) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
	/* Change the carry */
	proc->carry ^= proc->carry;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
	#endif
}
