/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_and_or_xor_routine.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:37:40 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/21 14:53:39 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction_parse.h"
#include "endian.h"

//TODO : libs

#include "ft_printf.h"
void			ft_vm_instr_and_or_xor_routine(t_vm *vm,
											t_process *proc,
											t_instr *instr)
{
	int			i;

	i = 0;
	if (DISPLAY_4)
		ft_printf("P %4d | %s ", -proc->process_nb, instr->op->name);
	while (i < (instr->op->nb_args - 1))
	{
		if (instr->args[i].type == REG_CODE)
		{
			instr->args[i].data = proc->reg[instr->args[i].data];
			if (DISPLAY_4)
				ft_printf("%d ", instr->args[i].data);
		}
		else if (instr->args[i].type == IND_CODE)
		{
			instr->args[i].data =
				ft_instruction_get_data(REG_SIZE,
					&vm->arena[0][MOD(proc->pc - vm->arena[0] + (instr->args[i].data % IDX_MOD))],
					&vm->arena[0][0],
					IS_BIG_ENDIAN);
			if (DISPLAY_4)
				ft_printf("%d ", instr->args[i].data);
		}
		else
		{
			if (DISPLAY_4)
				ft_printf("%d ", instr->args[i].data);
			instr->args[i].data = ft_endian_convert_int32(instr->args[i].data);
		}
		++i;
	}
	ft_printf("r%d\n", instr->args[2].data);
}
