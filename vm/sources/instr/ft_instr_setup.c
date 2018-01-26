/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:03:21 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/26 16:57:29 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

#include "ft_printf.h"
uint8_t			ft_instr_setup(t_vm *vm, t_proc *proc)
{
	extern t_op			g_op_tab[17];
	uint8_t				bytecode;

	/* Fetch the instruction according to next_op */
	proc->instr->op = g_op_tab + proc->next_op;
	/* Read the bytecode if any and setup the 1st argument */
	if (proc->instr->op->param_byte)
	{
		bytecode = vm->arena[0][LOOP(proc->pc + 1)];
		proc->instr->new_pc = LOOP(proc->pc + 2);
		proc->instr->size += 2;
	}
	/* Create a new bytecode with a default DIR_CODE */
	else
	{
		bytecode = DIR_CODE << 6;
		proc->instr->new_pc = LOOP(proc->pc + 1);
		proc->instr->size += 1;
	}
	return (bytecode);
}
