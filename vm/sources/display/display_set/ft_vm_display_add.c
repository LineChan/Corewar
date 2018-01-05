/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:32:30 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/21 14:53:17 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void				ft_vm_display_add(t_vm *vm,
										t_process const *proc,
										t_instr const *instr)
{
	if (DISPLAY_4)
	{
		ft_printf("P %4d | add r%d r%d r%d\n",
			-proc->process_nb,
			instr->args[0].data,
			instr->args[1].data,
			instr->args[2].data);
	}
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc, instr);
}
