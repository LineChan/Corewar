/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_parse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoelling          #+#    #+#             */
/*   Updated: 2017/12/15 16:24:20 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction_parse.h"
#include "endian.h"

static int32_t	ft_instruction_parse_data(t_instr *this,
										  uint8_t *context,
										  uint8_t bytecode,
										  int i)
{
	/* Parse size */
	this->args[i].type = (bytecode >> 6) & 0x3;

	/* get size from type */
	if (REG_CODE == this->args[i].type)
		this->args[i].size = 1;
	else if (DIR_CODE == this->args[i].type)
		this->args[i].size = (!this->op->has_index) ? 4 : 2;
	else if (IND_CODE == this->args[i].type)
		this->args[i].size = 2;
	else
		return (0);

	/* read data byte by byte */
	this->args[i].data = ft_instruction_get_data(this->args[i].size,
											     this->new_pc,
											     context,
											     IS_BIG_ENDIAN);
	/* Check if register number is valide */
	if (REG_CODE == this->args[i].type && !REG_IS_VALID(this->args[i].data))
		return (0);
	return (1);
}

int32_t		ft_instruction_parse(t_instr *this,
								 uint8_t *context,
								 uint8_t bytecode,
								 int *error)
{
	int		i;

	i = 0;
	/* Parse each arg defined */
	while (i < this->op->nb_args)
	{
		if (0 == ft_instruction_parse_data(this, context, bytecode, i))
		{
			*error = 1;
		}
		/* Next loop, prepare bytecode, handle pc jump */
		bytecode <<= 2;
		this->new_pc = context + LOOP(this->new_pc + this->args[i].size - context);
		++i;
	}
	if (*error == 1)
		return (0);
	return (1);
}
