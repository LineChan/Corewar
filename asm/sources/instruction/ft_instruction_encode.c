/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_encode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/04 14:27:07 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "ft_string.h"
#include "endian.h"

t_instr			*ft_instruction_encode(int tab_size, char **tab)
{
	extern t_op	g_op_tab[17];
	t_instr		*st;
	int			i;

	/* Find correct instruction offset in g_op_tab */
	i = 1;
	while (17 > i && 0 != ft_strcmp(g_op_tab[i].name, tab[0]))
		++i;
	if (17 == i)
		return (0);
	/* Allocate the wrapper */
	st = ft_memalloc(sizeof(t_instr));
	st->op = &g_op_tab[i];
	st->bytecode = ft_instruction_encode_set_args(st, tab_size, tab + 1);
	return (st);
}
