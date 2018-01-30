/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_zjmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:13:00 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/29 21:24:35 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_printf.h"

void			ft_instr_zjmp(t_vm *vm, t_proc *proc)
{
	/* Execute the instruction only if the carry is equal to 1 */
	if (!proc->carry)
	{
		if (DISPLAY_4)
		{
			ft_printf("P %4d | zjmp %d FAILED\n",
							-proc->proc_nb,
							proc->instr->args[0].data);
		}
	}
	else
	{
		if (DISPLAY_4)
		{
			ft_printf("P %4d | zjmp %d OK\n",
							-proc->proc_nb,
							proc->instr->args[0].data);
		}
		proc->instr->zjmp_success = 1;
		vm->visual.pc_position[proc->pc] = 0;
		/* Get the new position for the Program Counter */
		proc->instr->new_pc = LOOP(proc->pc + (proc->instr->args[0].data % IDX_MOD));
		vm->visual.pc_position[proc->instr->new_pc] = proc->parent_nb;
	}
}
