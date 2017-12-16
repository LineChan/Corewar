/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_decode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoelling          #+#    #+#             */
/*   Updated: 2017/12/15 16:22:40 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction_parse.h"
#include "ft_string.h"

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
