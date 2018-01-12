/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_live.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:21:34 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/12 17:09:40 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

//TODO: libs
#include "ft_printf.h"
#include <libc.h>
void           ft_vm_instr_live(t_vm *vm, t_process *proc, t_instr *instr)
{
	t_list			*it;

	//ft_printf("live by proc %d\n", -proc->process_nb);
	++vm->total_live;
	proc->has_lived = vm->current_cycle;
	it = 0;
	/* Find the champion that benefits from the live instruction */
	if ((it = ft_vm_find_proc_nb(&vm->process_head, instr->args[0].data)))
	{
		/* The lastest champion to do live wins */
		vm->last_alive = C_PROCESS(it)->parent_nb;
		++C_PROCESS(it)->live;
	}
	/* Display additional informations */
	//ft_printf("STOP LIVE  DUMP in %d\n", DUMP_OPT);
	if (DISP_OPT)
	{
		ft_vm_display_live(vm, proc, it, instr);
	}
	/* Write in the log file */
	if (LOG_OPT)
		ft_vm_log_live(vm, proc, it);
	/* Fetch the next instruction */
	proc->pc = instr->new_pc;
}
