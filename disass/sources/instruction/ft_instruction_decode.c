/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_decode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/13 20:50:36 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "ft_string.h"

t_instr		*ft_instruction_decode(uint8_t *pc)
{
	extern t_op		g_op_tab[17];
	uint8_t			bytecode;
	t_instr			*this;

	/* Check for pc correctness */
	if (!OPCODE_IS_VALID(*pc))
		return (0);
	/* create new instruction */
	this = ft_memalloc(sizeof(*this));
	/* get bytecode and setup pc to the first arg */
	bytecode = ft_instruction_setup(this, pc);
	/* parse instructions from the bytecode */
	if (0 == ft_instruction_parse(this, bytecode))
		ft_instruction_del(&this);
	return (this);
}
