/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_update_exec_cycle.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:21:03 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/27 16:49:46 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void		ft_instr_update_exec_cycle(t_proc *proc)
{
	extern t_op			g_op_tab[17];

	/* If the op number is valid, the 1st instrucion starts after its sleep time */
	if (OPCODE_IS_VALID(proc->next_op))
		proc->exec_cycle += g_op_tab[proc->next_op].nb_cycles;
	/* Otherwsise it starts at the next cycle */
	else
		++proc->exec_cycle;
}
