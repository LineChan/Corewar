/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_setup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/13 20:51:32 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"

uint8_t		ft_instruction_setup(t_instr *this, uint8_t *pc)
{
	extern t_op		g_op_tab[17];
	uint8_t			bytecode;

	/* Setup the op_tab pointer */
	this->op = g_op_tab + *pc;

	/* Read the param_byte and setup the first argument */
	if (0 != this->op->param_byte)
	{
		bytecode = pc[1];
		this->new_pc = pc + 2;
	}

	/* Else, create new one with default DIR_CODE */
	else
	{
		bytecode = DIR_CODE << 6;
		this->new_pc = pc + 1;
	}
	return (bytecode);
}
