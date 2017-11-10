/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_jump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 01:24:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/10 11:59:13 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO : presentation

#include "ft_vm.h"
#define BYTECODE_GET(bc, pos)	(((bc) >> (8 - ((pos) << 1))) & 0x3)

extern uint8_t	g_direct_jump_table_from_instr[17];


int				ft_vm_instr_jump(t_champion *champ)
{
	int		i;

	i = 0;
	ft_printf("{yellow:Jump} IN\n");
	while (i < champ->instr.op->nb_args)
	{
		if (BYTECODE_GET(champ->instr.bytecode, i + 1) == IND_CODE)
		{
			DEBUG_MODE ? ft_fprintf(2, "T_IND\n") : 0;
			champ->instr.arg_jump[i] = 2;
			champ->instr.op->arg_types[i] = T_IND;
		}
		else if (BYTECODE_GET(champ->instr.bytecode, i + 1) == REG_CODE)
		{
			DEBUG_MODE ? ft_fprintf(2, "T_REG\n") : 0;
			champ->instr.arg_jump[i] = 1;
			champ->instr.op->arg_types[i] = T_REG;
		}
		else if (BYTECODE_GET(champ->instr.bytecode, i + 1) == DIR_CODE)
		{
			DEBUG_MODE ? ft_fprintf(2, "T_DIR\n") : 0;
			champ->instr.arg_jump[i] = g_direct_jump_table_from_instr[champ->instr.op->numero];
			champ->instr.op->arg_types[i] = T_DIR;
			}
		else
		{
			ft_printf("{yellow:Jump} out {red:KO}\n");
			return (EXIT_FAILURE);
		}
		++i;
	}
	ft_printf("{yellow:Jump} out {green:OK}\n");
	return (EXIT_SUCCESS);
}
