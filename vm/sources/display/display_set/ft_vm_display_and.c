/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_and.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:51:12 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/13 16:58:13 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void			ft_vm_display_and(t_vm *vm,
								t_process const *proc,
								t_instr const *instr)
{
	if (DISPLAY_4)
	{
		ft_printf("P    %d | and %d %d r%d\n",
			proc->parent_nb,
			instr->args[0].data,
			instr->args[1].data,
			instr->args[2].data);
	}
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc, instr);
}
