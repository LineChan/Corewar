/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_lld.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:11:26 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/08 18:13:04 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

static void		ft_vm_display_instr(t_process *proc, const unsigned char *ptr,
									const int address)
{
	(void)address;
	if (proc->op->arg_types[0] == T_DIR)
		ft_printf("P    %d | lld %d r%d\n", proc->parent_nb, address, *ptr);
	else
		ft_printf("P    %d | lld %d r%d\n", proc->parent_nb,  proc->reg[*ptr], *ptr);

}

void			ft_vm_display_lld(t_vm *vm, t_process *proc,
									const unsigned char *ptr,
									const int address)
{
	DISPLAY_4 ? ft_vm_display_instr(proc, ptr, address) : 0;
	DISPLAY_16 ? ft_vm_display_pc(vm, proc, 2 + proc->jump[0] + proc->jump[1]) : 0;
}
