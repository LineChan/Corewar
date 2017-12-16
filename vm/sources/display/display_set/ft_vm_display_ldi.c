/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_ldi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 21:26:34 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/16 17:39:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void			ft_vm_display_ldi(t_vm *vm,
								t_process const *proc,
								t_instr const *instr)
{
	if (DISPLAY_4)
	{
		ft_printf("P    %d | ldi %d %d r%d\n",
						proc->parent_nb,
						instr->args[0].data,
						instr->args[1].data,
						instr->args[2].data);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
						instr->args[0].data,
						instr->args[1].data,
						instr->args[0].data + instr->args[1].data,
						proc->pc - vm->arena[0] + (instr->args[0].data + instr->args[1].data) % IDX_MOD);
	}
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc, instr);
}
