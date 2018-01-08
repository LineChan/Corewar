/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_zjmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:48:01 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/06 18:05:14 by mvillemi         ###   ########.fr       */
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
		proc->pc += 3;
		/* Write in the logfile */
		ft_vm_log_zjmp(vm, proc);
	}
	else
	{
		if (DISPLAY_4)
		{
			ft_printf("P %4d | zjmp %d OK\n",
							-proc->process_nb,
							instr->args[0].data);
							//proc->pc - instr->new_pc);
		}
		/* Write in the logfile */
		ft_vm_log_zjmp(vm, proc);
		/* Set the Program Counter at its new position */
		proc->pc = &vm->arena[0][MOD(proc->pc - vm->arena[0] + (instr->args[0].data % IDX_MOD))];
	}
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
