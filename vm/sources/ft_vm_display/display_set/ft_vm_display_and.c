/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_and.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:51:12 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 16:21:13 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

static void		ft_vm_display_instr(t_process const *proc, const unsigned char *ptr,
									const int and[2])
{
	ft_printf("P    %d | and %d %d r%d\n", proc->parent_nb, and[0], and[1], *ptr);
}

void			ft_vm_display_and(t_vm *vm,
								t_process const *proc,
								unsigned char const *ptr,
								const int and[2])
{
	if (DISPLAY_4)
		ft_vm_display_instr(proc, ptr, and);
	if (DISPLAY_16)
	{
		ft_vm_display_pc(vm, proc,
			2 + proc->jump[0] + proc->jump[1] + proc->jump[2]);
	}
}
