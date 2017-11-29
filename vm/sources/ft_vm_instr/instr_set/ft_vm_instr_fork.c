/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:52:21 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/29 01:16:16 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void				ft_vm_instr_fork(t_vm *vm, t_process *proc)
{
	extern uint8_t g_direct_jump_table_from_instr[17];

	/* Create a new process, copy data from parent */
	/* and link it to the champion's structure at the right location */
	ft_vm_new_process_kid(vm, proc, MOD((proc->pc - vm->arena[0] +
	(ft_instruction_get_data(g_direct_jump_table_from_instr[proc->op->numero],
									proc->pc + 1) % IDX_MOD))));
	/* Update the execution cycle with the new instruction */
}
