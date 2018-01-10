/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_setup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/08 22:19:28 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_string.h"

#include "ft_printf.h"
uint8_t		ft_instruction_setup(t_vm *vm, t_process *proc)
{
    extern t_op		g_op_tab[17];
	uint8_t			bytecode;

	/* Create new instruction */
	proc->instr = ft_memalloc(sizeof(t_instr));
	/* Fetch the right instruction */
	proc->instr->op = g_op_tab + *proc->pc;
	//proc->instr->op = &g_op_tab[*proc->pc];
	//ft_printf("{blue:SEGFAULT\n}");
	/* Read the param_byte and setup the first argument */
	if (0 != proc->instr->op->param_byte)
	{
		bytecode = vm->arena[0][LOOP(proc->pc + 1 - vm->arena[0])];
		proc->instr->new_pc = vm->arena[0] + LOOP(proc->pc + 2 - vm->arena[0]);
	}
	/* Create a new bytecode with a default DIR_CODE */
	else
	{
		bytecode = DIR_CODE << 6;
		proc->instr->new_pc = vm->arena[0] + LOOP(proc->pc + 1 - vm->arena[0]);
	}
	return (bytecode);
}
#if 0
uint8_t		ft_instruction_setup(t_instr *this, uint8_t *pc, uint8_t *context)
{
	extern t_op		g_op_tab[17];
	uint8_t			bytecode;

	/* Setup the op_tab pointer */
	this->op = g_op_tab + *pc;

	/* Read the param_byte and setup the first argument */
	if (0 != this->op->param_byte)
	{
		bytecode = context[LOOP(pc + 1 - context)];
		this->new_pc = context + LOOP(pc + 2 - context);
	}

	/* Else, create new one with default DIR_CODE */
	else
	{
		bytecode = DIR_CODE << 6;
		this->new_pc = context + LOOP(pc + 1 - context);
	}
	return (bytecode);
}
#endif
