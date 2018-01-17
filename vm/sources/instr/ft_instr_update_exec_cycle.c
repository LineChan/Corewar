/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_update_exec_cycle.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:21:03 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/17 17:42:14 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void		ft_instr_update_exec_cycle(t_vm *vm, t_proc *proc)
{
	extern t_op			g_op_tab[17];

	/* If the op number is valid, the 1st instrucion starts aftr its sleep time */
	if (OPCODE_IS_VALID(vm->arena[0][proc->pc]))
		proc->exec_cycle += g_op_tab[proc->pc].nb_cycles;
	/* Otherwsise it starts at the next cycle */
	else
		++proc->exec_cycle;
}
