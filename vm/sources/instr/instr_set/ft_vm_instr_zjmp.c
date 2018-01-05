/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_zjmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:48:01 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/05 23:00:45 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_printf.h"

void			ft_vm_instr_zjmp(t_vm *vm, t_process *proc, t_instr *instr)
{
	/* Execute the instruction only if the carry value is 1 */
	if (!proc->carry)
	{
		if (DISPLAY_4)
		{
			ft_printf("P %4d | zjmp %d FAILED\n",
							-proc->process_nb,
							instr->args[0].data);
		}
		if (DISPLAY_16)
			ft_vm_display_pc(vm, proc, instr);
		/* Fetch the next instruction */
		ft_vm_log_zjmp(vm, proc, instr);
		proc->pc += 3;
		//++proc->exec_cycle;
		/* Update the execution cycle with the new instruction */
		ft_vm_instr_update_exec_cycle(vm, proc);
		ft_printf("xzjmp next op : %x\nat %#0.4x\n", *proc->pc, proc->pc - vm->arena[0]);
		return ;
	}
	if (DISPLAY_4)
	{
		ft_printf("P %4d | zjmp %d OK\n",
						-proc->process_nb,
						instr->args[0].data);
						//proc->pc - instr->new_pc);
	}
	//ft_printf("isntr jump segfault\n");
	/* Set the Program Counter at its new position */
	proc->pc = &vm->arena[0][MOD(proc->pc - vm->arena[0] + (instr->args[0].data % IDX_MOD))];
	ft_vm_log_zjmp(vm, proc, instr);
	/* Write in the logfile */
	//TODO : logfile
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
