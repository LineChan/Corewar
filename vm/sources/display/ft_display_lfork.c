/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_lfork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:17:33 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/19 16:18:54 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void			ft_display_lfork(t_vm *vm, t_proc const *proc)
{
	if (DISPLAY_4)
	{
		ft_printf("P %4d | lfork %d (%d)\n",
					-proc->proc_nb,
					proc->instr->args[0].data,
					proc->pc + proc->instr->args[0].data);
	}
	if (DISPLAY_16)
		ft_display_pc(vm, proc);
}
