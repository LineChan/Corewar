/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_ld.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:48:18 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/05 01:19:15 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

static void		ft_vm_display_instr(t_process *proc, const unsigned char *ptr,
									const unsigned int address)
{
	if (proc->op->arg_types[0] == T_IND)
	{
		ft_printf("P    %d | ld %d r%d\n", proc->parent_nb, proc->reg[*ptr], *ptr);
	}
	else
	{
		ft_printf("P    %d | ld %d r%d\n", proc->parent_nb,  address, *ptr);
	}
}

void			ft_vm_display_ld(t_vm *vm,
								t_process *proc,
								const unsigned char *ptr,
								const unsigned int address)
{
	DISPLAY_4 ? ft_vm_display_instr(proc, ptr, address) : 0;
	DISPLAY_16 ? ft_vm_display_pc(vm, proc, 2 + proc->jump[0] + proc->jump[1]) : 0;
}
