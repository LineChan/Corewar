/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_decode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/12 16:09:17 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

#include "ft_printf.h"
uint8_t		ft_instruction_decode(t_vm *vm, t_process *proc)
{
    uint8_t         bytecode;

	/* Check if the OP code is valid */
    if (!OPCODE_IS_VALID(proc->next_op))
        return (OPCODE_NOT_VALID);
	/* Decode the bytecode */
    bytecode = ft_instruction_setup(vm, proc);
	/* Parse instruction */
	return (ft_instruction_parse(vm, proc, bytecode));
}

#if 0
t_instr		*ft_instruction_decode(uint8_t *pc, uint8_t *context, int *error)
{
	extern t_op		g_op_tab[17];
	uint8_t			bytecode;
	t_instr			*this;

	*error = 0;
	/* Check for pc correctness */
	if (!OPCODE_IS_VALID(*pc))
		return (0);
	/* create new instruction */
	this = ft_memalloc(sizeof(*this));
	/* get bytecode and setup pc to the first arg */
	bytecode = ft_instruction_setup(this, pc, context);
	/* parse instructions from the bytecode */
	ft_instruction_parse(this, context, bytecode, error);
	return (this);
}
#endif
