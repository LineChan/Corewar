/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_live.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:46:42 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/25 21:29:00 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_printf.h"

void			ft_display_live(t_vm *vm, t_proc const *proc, t_list const *it)
{
	/* Display the instruction */
	if (DISPLAY_4)
	{
		ft_printf("P %4d | live %d\n",
			-proc->proc_nb, proc->instr->args[0].data);
	}
	/* Display live */
	if ((DISPLAY_1 && it) ||
		((C_PROCESS(it)->parent_nb < 0) && (C_PROCESS(it)->parent_nb > -5)))
	{
		ft_printf("Player %d (%s) is said to be alive\n",
					C_PROCESS(it)->parent_nb,
					vm->header[C_PROCESS(it)->parent_nb - 1].prog_name);
	}
	/* Display the number of cycle since the last live */
	if (DISPLAY_8)
		vm->opt.death[proc->parent_nb - 1] = vm->current_cycle;
	if (DISPLAY_16)
		ft_display_pc(vm, proc);
}
