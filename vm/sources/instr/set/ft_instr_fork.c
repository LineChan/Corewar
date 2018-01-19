/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:05:21 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/19 14:32:11 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void			ft_instr_fork(t_vm *vm, t_proc *proc)
{
	/* Create a new process, copy data from parent and link it
		to the Processses' list */
	ft_new_proc_kid(vm, proc,
		MOD(proc->pc + (proc->instr->args[0].data % IDX_MOD)));
	if (DISP_OPT)
		ft_display_fork(vm, proc);
}
