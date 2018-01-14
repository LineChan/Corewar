/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_update_exec_cycle.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 00:00:48 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 22:52:30 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

//TODO : libs
#include "ft_printf.h"
void		ft_vm_instr_update_exec_cycle(t_vm *vm, t_process *proc)
{
	//ft_printf("update exec cycle !!\n\n");
	extern t_op			g_op_tab[17];

	(void)vm;
	//ft_printf("update exec cycle IN : %d\n", proc->exec_cycle);
	#if 0
	if ((proc->pc - vm->arena[0]) > MEM_SIZE)
		proc->pc = vm->arena[0] + (proc->pc - vm->arena[0]) % MEM_SIZE;
		#endif
		//proc->pc = vm->arena[0];
	if (OPCODE_IS_VALID(proc->next_op))
		proc->exec_cycle += g_op_tab[proc->next_op].nb_cycles;
	else
		proc->exec_cycle += 1;
		//if (proc->process_nb == -3)
	//ft_printf("update exec cycle OUT : %d\n", proc->exec_cycle);
}
