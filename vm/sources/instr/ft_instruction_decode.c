/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_decode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/08 22:19:23 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

#include "ft_printf.h"
void		ft_instruction_decode(t_vm *vm, t_process *proc)
{
    uint8_t         bytecode;

	/* Check if the OP code is valid */
    if (!OPCODE_IS_VALID(*proc->pc))
        return ;
	/* Decode the bytecode */
	//ft_printf("{red:SEGFAULT\n}");
    bytecode = ft_instruction_setup(vm, proc);
	/* Parse instruction */
	ft_instruction_parse(vm, proc, bytecode);
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
