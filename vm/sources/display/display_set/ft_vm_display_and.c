/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_and.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:51:12 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/21 14:54:24 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void			ft_vm_display_and(t_vm *vm,
								t_process const *proc,
								t_instr const *instr)
{
	if (DISPLAY_4)
	{
		ft_printf("P %4d | and %d %d r%d\n",
			-proc->process_nb,
			instr->args[0].data,
			instr->args[1].data,
			instr->args[2].data);
	}
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc, instr);
}