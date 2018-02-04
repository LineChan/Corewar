/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_encode_set_args.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/20 15:54:21 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "endian.h"

int8_t	ft_instruction_encode_set_args(t_instr *st, int tab_size, char **tab)
{
	int 	i;
	uint8_t	type;
	uint8_t	bytecode;

	i = 0;
	bytecode = 0;
	st->instr_size = 1 + st->op->param_byte;
	while (i < st->op->nb_args && i < tab_size)
	{
		if ('r' == tab[i][0])
			type = ft_instruction_encode_reg(st, i, tab[i]);
		else if (DIRECT_CHAR == tab[i][0])
			type = ft_instruction_encode_dir(st, i, tab[i]);
		else
			type = ft_instruction_encode_ind(st, i, tab[i]);
		st->instr_size += st->args[i].size;	
		bytecode |= type << (6 - (i << 1));
		++i;
	}
	if (0 == st->op->param_byte)
		return (0);
	return (bytecode);
}
