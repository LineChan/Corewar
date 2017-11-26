/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_live.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:21:34 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/26 01:34:43 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO: libc
#include "ft_printf.h"
void           ft_vm_instr_live(t_vm *vm, t_process *proc)
{
	int				number;
	t_list			*it;
	extern int8_t	g_direct_jump_table_from_instr[17];
	extern t_op		g_op_tab[17];

	//number = ft_instr_
	ft_printf("live\n");
	number =
		ft_instruction_get_data(g_direct_jump_table_from_instr[proc->op->numero],
		proc->pc + 1);
	ft_printf("{green:START LOOP}\n");
	if ((it = ft_vm_find_proc_nb(&vm->process_head, number)))
	{
		vm->last_alive = C_PROCESS(it)->parent_nb - 1;
		++C_PROCESS(it)->live;
	}
	ft_printf("{green:START END}\n");
	/* Write in the log file */
	LOG_OPT ? ft_vm_log_live(vm, proc, it) : 0;
	/* Fetch the next instruction */
	proc->pc += 1 + g_direct_jump_table_from_instr[proc->op->numero];
	/* Add its sleeping time to execution cycle */
	if (IS_INSTR(*proc->pc))
		proc->exec_cycle += g_op_tab[*proc->pc].nb_cycles;
	else
		proc->exec_cycle += 1;
		ft_printf("live exec_cycle : %d\n", proc->exec_cycle);
}
