/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:05:21 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/29 20:48:39 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_printf.h"

void			ft_instr_fork(t_vm *vm, t_proc *proc)
{
	/* Create a new process, copy data from parent and link it
		to the Processses' list */
	ft_new_proc_kid(vm, proc,
		LOOP(proc->pc + (proc->instr->args[0].data % IDX_MOD)));

	if (DISPLAY_4)
	{
		ft_printf("P %4d | fork %d (%d)\n",
					-proc->proc_nb,
					proc->instr->args[0].data,
					proc->pc + (proc->instr->args[0].data % IDX_MOD));
	}
}
