/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_live.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:21:34 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/11 14:48:39 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO: libs
#include "ft_printf.h"
#include <libc.h>
void           ft_vm_instr_live(t_vm *vm, t_process *proc)
{
	int				number;
	t_list			*it;
	extern int8_t	g_direct_jump_table_from_instr[17];

	++vm->total_live;
	/* Fetch the champion's number */
	proc->has_lived = vm->current_cycle;
	number =
		ft_vm_instr_get_data(g_direct_jump_table_from_instr[proc->op->numero],
		proc->pc + 1, vm);
	/* Find the champion that benefits from the live instruction */
	if ((number < 0) && (number > -5) &&
			(it = ft_vm_find_proc_nb(&vm->process_head, number)))
	{
		/* The lastest champion to do live wins */
		vm->last_alive = C_PROCESS(it)->parent_nb;
		++C_PROCESS(it)->live;
	}
	/* Display additional informations */
	DISP_OPT ? ft_vm_display_live(vm, proc, it, number) : 0;
	/* Write in the log file */
	LOG_OPT ? ft_vm_log_live(vm, proc, it) : 0;
	/* Fetch the next instruction */
	proc->pc += 1 + g_direct_jump_table_from_instr[proc->op->numero];
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
}
