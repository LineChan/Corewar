/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_or.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 01:17:42 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/05 18:55:19 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

static void		ft_vm_display_instr(t_process *proc, const unsigned char *ptr,
									const int or[2])
{
	ft_printf("P    %d | or %d %d r%d\n", proc->parent_nb, or[0], or[1], *ptr);
}

void			ft_vm_display_or(t_vm *vm,
								t_process *proc,
								const unsigned char *ptr,
								const int or[2])
{
	DISPLAY_4 ? ft_vm_display_instr(proc, ptr, or) : 0;
	DISPLAY_16 ? ft_vm_display_pc(vm, proc,
			2 + proc->jump[0] + proc->jump[1] + proc->jump[2]) : 0;
}
