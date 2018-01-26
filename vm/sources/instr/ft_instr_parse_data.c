/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_parse_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:39:34 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/26 01:19:46 by mvillemi         ###   ########.fr       */
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
		proc->instr->size += 1;
		proc->instr->args[i].data = ft_arena_get_int8(vm, proc->instr->new_pc);
		proc->instr->new_pc += 1;
		proc->instr->new_pc %= MEM_SIZE;
	}
	else if (DIR_CODE == proc->instr->args[i].type)
	{
		proc->instr->args[i].type = T_DIR;
		if (proc->instr->op->has_index)
			proc->instr->args[i].data = ft_arena_get_int16(vm, proc->instr->new_pc);
		else
			proc->instr->args[i].data = ft_arena_get_int32(vm, proc->instr->new_pc);
		proc->instr->size += (!proc->instr->op->has_index) ? 4 : 2;
		proc->instr->new_pc += (!proc->instr->op->has_index) ? 4 : 2;
		proc->instr->new_pc %= MEM_SIZE;
	}
	else if (IND_CODE == proc->instr->args[i].type)
	{
		proc->instr->args[i].type = T_IND;
		proc->instr->size += 2;
		proc->instr->args[i].data = ft_arena_get_int16(vm, proc->instr->new_pc);
		proc->instr->new_pc += 2;
		proc->instr->new_pc %= MEM_SIZE;
	}
	else
		return (EXIT_FAILURE);
	/* Read data byte by byte */
	/* Check is the argument's type matches op.c */
	if (((proc->instr->args[i].type & proc->instr->op->arg_types[i]) == 0) ||
	/* If the argument is a register, check if its number is valid */
		((T_REG == proc->instr->args[i].type)
		&& !REG_IS_VALID(proc->instr->args[i].data)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
