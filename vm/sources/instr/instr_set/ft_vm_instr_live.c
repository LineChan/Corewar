/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_live.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:21:34 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/15 18:08:47 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

#include "ft_printf.h"
void           ft_vm_instr_live(t_vm *vm, t_process *proc)
{
	t_list			*it;

	++vm->total_live;
	proc->has_lived = vm->current_cycle;
	it = 0;
	/* Find the process that benefits from the live instruction */
	if ((proc->instr->args[0].data > 0) && (proc->instr->args[0].data < 4) &&
		((it = ft_vm_find_proc_nb(&vm->process_head, proc->instr->args[0].data))))
		if ((it = ft_vm_find_proc_nb(&vm->process_head, proc->instr->args[0].data)))
	{
		ft_fprintf(2, "proc->instr->args[0].data : %d\n", proc->instr->args[0].data);
		ft_fprintf(2, "current_cycle : %d\n", vm->current_cycle);
		ft_fprintf(2, "C_PROCESS(it)->process_nb : %d found !\n", C_PROCESS(it)->process_nb);
		/* The lastest champion to do live wins */
		vm->last_alive = C_PROCESS(it)->parent_nb;
		++C_PROCESS(it)->live;
	}
	/* Display additional informations */
	if (DISP_OPT)
		ft_vm_display_live(vm, proc, it);
	#if 0
	/* Write in the log file */
	if (LOG_OPT)
		ft_vm_log_live(vm, proc, it);
	#endif
	/* Fetch the next instruction */
	proc->pc = proc->instr->new_pc;
}
