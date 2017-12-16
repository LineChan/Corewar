/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_setup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoelling          #+#    #+#             */
/*   Updated: 2017/12/15 14:50:20 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction_parse.h"

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
