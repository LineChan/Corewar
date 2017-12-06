/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:32:30 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/06 14:53:38 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

static void			ft_vm_display_instr(t_process *proc,
										const int add[3])
{
	ft_printf("P    %d | add r%d r%d r%d\n", proc->parent_nb, add[0],
		add[1], add[2]);
}
void				ft_vm_display_add(t_vm *vm, t_process *proc, const int add[3])
{
	DISPLAY_4 ? ft_vm_display_instr(proc, add) : 0;
	DISPLAY_16 ? ft_vm_display_pc(vm, proc,
		2 + proc->jump[0] + proc->jump[1] + proc->jump[2]) : 0;
}
