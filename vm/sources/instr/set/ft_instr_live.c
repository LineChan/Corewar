/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_live.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:21:53 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/27 15:40:36 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_printf.h"

void			ft_instr_live(t_vm *vm, t_proc *proc)
{
	/* Count of live instructions during the current round */
	++vm->total_live;
	proc->has_lived = vm->current_cycle;
	/* Display the instruction */
	if (DISPLAY_4)
	{
		ft_printf("P %4d | live %d\n",
			-proc->proc_nb, proc->instr->args[0].data);
	}
	/* Find the process called by the instruction */
	if ((proc->instr->args[0].data >= -MAX_PLAYERS)
		&& (proc->instr->args[0].data < 0))
	{
		/* Keep the last process that lived */
		vm->last_alive = -proc->instr->args[0].data;
		if (DISPLAY_1)
		{
			ft_printf("Player %d (%s) is said to be alive\n",
						-proc->instr->args[0].data,
						vm->header[-proc->instr->args[0].data - 1].prog_name);
		}
	}
	if (DISPLAY_8)
		vm->opt.death[proc->parent_nb - 1] = vm->current_cycle;
	#if 0
	if (DISPLAY_16)
		ft_display_pc(vm, proc);
		#endif
}
