/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:49:42 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/06 14:54:45 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

static void		ft_vm_display_instr(t_process *proc, const int sub[3])
{
	ft_printf("P    %d | sub r%d r%d r%d\n", proc->parent_nb, sub[0],
		sub[1], sub[2]);
}

void			ft_vm_display_sub(t_vm *vm, t_process *proc, const int sub[3])
{
	DISPLAY_4 ? ft_vm_display_instr(proc, sub) : 0;
	DISPLAY_16 ? ft_vm_display_pc(vm, proc,
		2 + proc->jump[0] + proc->jump[1] + proc->jump[2]) : 0;
}
