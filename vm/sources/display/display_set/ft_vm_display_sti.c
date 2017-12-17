/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_sti.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:51:53 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/17 14:24:18 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void			ft_vm_display_sti(t_vm *vm,
								t_process const *proc,
								t_instr const *instr)
{
	if (DISPLAY_4)
	{
		ft_printf("P    %d | sti r%d %d %d\n",
					proc->parent_nb,
					instr->args[0].data,
					instr->args[1].data,
					instr->args[2].data);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
					instr->args[1].data % MEM_SIZE,
					instr->args[2].data % MEM_SIZE,
					(instr->args[1].data + instr->args[2].data) % MEM_SIZE,
					proc->pc - vm->arena[0] +
					(instr->args[1].data + instr->args[2].data) % IDX_MOD);
	}
	if (DISPLAY_16)
		ft_vm_display_pc(vm, proc, instr);
	#if 0
	ft_printf("P    %d | sti r%d %d %d\n",
				proc->parent_nb, *(proc->pc + 2),
				address[0] % MEM_SIZE, address[1] % MEM_SIZE);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
				address[0] % MEM_SIZE,
				address[1] % MEM_SIZE, (address[0] + address[1]) % MEM_SIZE,
				proc->pc - vm->arena[0] + (address[0] + address[1]) % IDX_MOD);
	#endif
}

/*
It is now cycle 25
P    1 | sti r1 0 0
       | -> store to 0 + 0 = 0 (with pc and mod 0)
*/
