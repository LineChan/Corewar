/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:08:06 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/19 14:09:23 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void			ft_display_fork(t_vm *vm, t_proc const *proc)
{
	if (DISPLAY_4)
	{
		ft_printf("P %4d | fork %d (%d)\n",
					-proc->proc_nb,
					proc->instr->args[0].data,
					proc->pc + (proc->instr->args[0].data % IDX_MOD));
	}
	if (DISPLAY_16)
		ft_display_pc(vm, proc);
}
