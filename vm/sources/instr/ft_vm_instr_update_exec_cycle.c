/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_update_exec_cycle.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 00:00:48 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/12 17:05:52 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

//TODO : libs
#include "ft_printf.h"
void		ft_vm_instr_update_exec_cycle(t_vm *vm, t_process *proc)
{
	extern t_op			g_op_tab[17];

	if ((proc->pc - vm->arena[0]) > MEM_SIZE)
		proc->pc = vm->arena[0] + (proc->pc - vm->arena[0]) % MEM_SIZE;
		//proc->pc = vm->arena[0];
	if (OPCODE_IS_VALID(proc->next_op))
		proc->exec_cycle += g_op_tab[*proc->pc].nb_cycles;
	else
		proc->exec_cycle += 1;
}
