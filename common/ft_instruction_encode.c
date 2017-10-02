/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_encode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/02 01:10:52 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "ft_printf.h"
#include "ft_string.h"
#include <stdlib.h>

t_instr			*ft_instruction_encode(int argc, char **tab)
{
	extern t_op	g_op_tab[17];
	t_instr		*st;
	int			i;

	return (0);
	i = 1;
	st = (t_instr *)malloc(sizeof(t_instr));
	while (i < 17 && 0 != ft_strcmp(g_op_tab[i].name, tab[0]))
		++i;
	st->op = &g_op_tab[i];
	st->args.encode = (t_instr_encode *)malloc(st->op->nb_args * sizeof(0[st->args.encode]));
/*	if (0 == st->op->param_byte)
		jmp = ft_instruction_get_args(st, idx + 1, T_DIR << 6) - idx;
	else
		jmp = ft_instruction_get_args(st, idx + 2, idx[1]) - idx;
*/	st->instr_size = argc;
	return (st);
}
