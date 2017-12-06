/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_xor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:25:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/05 19:28:06 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

static void		ft_vm_display_instr(t_process *proc, const unsigned char *ptr,
									const int xor[2])
{
	ft_printf("P    %d | xor %d %d r%d\n", proc->parent_nb, xor[0], xor[1], *ptr);
}

void			ft_vm_display_xor(t_vm *vm,
								t_process *proc,
								const unsigned char *ptr,
								const int xor[2])
{
	DISPLAY_4 ? ft_vm_display_instr(proc, ptr, xor) : 0;
	DISPLAY_16 ? ft_vm_display_pc(vm, proc,
			2 + proc->jump[0] + proc->jump[1] + proc->jump[2]) : 0;
}
