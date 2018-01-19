/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_lfork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:13:44 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/19 16:22:00 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void			ft_instr_lfork(t_vm *vm, t_proc *proc)
{
	/* Create a new process, copy data from parent_nb and link it to
		the processes' list */
	ft_new_proc_kid(vm, proc, MOD(proc->pc + proc->instr->args[0].data));
	/* Display additional informations */
	if (DISP_OPT)
		ft_display_lfork(vm, proc);
}
