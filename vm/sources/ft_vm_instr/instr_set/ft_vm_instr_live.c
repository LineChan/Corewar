/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_live.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:21:34 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/26 14:07:14 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void           ft_vm_instr_live(t_vm *vm, t_process *proc)
{
	int				number;
	t_list			*it;
	extern int8_t	g_direct_jump_table_from_instr[17];
	extern t_op		g_op_tab[17];

	/* Fetch the champion's number */
	number =
		ft_instruction_get_data(g_direct_jump_table_from_instr[proc->op->numero],
		proc->pc + 1);
	/* Find the champion that benefits from the live instruction */
	if ((number < 0) && (number > -5) &&
			(it = ft_vm_find_proc_nb(&vm->process_head, number)))
	{
		/* The lastest champion to do live wins */
		vm->last_alive = C_PROCESS(it)->parent_nb;
		++C_PROCESS(it)->live;
	}
	/* Write in the log file */
	LOG_OPT ? ft_vm_log_live(vm, proc, it) : 0;
	/* Fetch the next instruction */
	proc->pc += 1 + g_direct_jump_table_from_instr[proc->op->numero];
	/* Add its sleeping time to execution cycle */
	if (IS_INSTR(*proc->pc))
		proc->exec_cycle += g_op_tab[*proc->pc].nb_cycles;
	else
		proc->exec_cycle += 1;
}
