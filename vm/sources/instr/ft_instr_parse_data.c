/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_parse_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:39:34 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/25 18:16:12 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

uint8_t			ft_instr_parse_data(t_vm *vm,
									t_proc *proc,
									uint8_t const i,
									uint8_t const bytecode)
{
	/* Get bytecode's value */
	proc->instr->args[i].type = (bytecode >> 6) & 0x3;
	if (REG_CODE == proc->instr->args[i].type)
	{
		proc->instr->args[i].type = T_REG;
		proc->instr->args[i].size = 1;
	}
	else if (DIR_CODE == proc->instr->args[i].type)
	{
		proc->instr->args[i].type = T_DIR;
		proc->instr->args[i].size = (!proc->instr->op->has_index) ? 4 : 2;
	}
	else if (IND_CODE == proc->instr->args[i].type)
	{
		proc->instr->args[i].type = T_IND;
		proc->instr->args[i].size = 2;
	}
	else
		return (EXIT_FAILURE);
	/* Read data byte by byte */
	#if 0
	proc->instr->args[i].data =
		ft_instr_get_data(vm, proc, proc->instr->args[i].size, IS_BIG_ENDIAN);
	#endif
	proc->instr->args[i].data = ft_instr_get_data(vm,
												proc->instr->args[i].size,
												&vm->arena[0][proc->instr->new_pc],
												IS_BIG_ENDIAN);
	/* Check is the argument's type matches op.c */
	if (((proc->instr->args[i].type & proc->instr->op->arg_types[i]) == 0) ||
	/* If the argument is a register, check if its number is valid */
		((T_REG == proc->instr->args[i].type)
		&& !REG_IS_VALID(proc->instr->args[i].data)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
