/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_jump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 01:24:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/01 15:11:46 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO : introduction

# include "ft_vm.h"

#define LAST(k,n) ((k) & ((1<<(n))-1))
#define MID(k,m,n) LAST((k)>>(m),((n)-(m)))

extern uint8_t	g_direct_jump_table_from_instr[17];
/*
mask = ~(~0 << (end - start + 1));
value = (n >> start) & mask;
*/

#define BYTECODE_GET(bc, pos)	(((bc) >> (8 - ((pos) << 1))) & 0x3)

#if 0
static void 			ft_vm_instr_save(t_champion *champ, int arg_nb, int type, int size)
{
	champ->instr.jump += size;
	champ->arg_types[arg_nb] = type;
}
#endif

void			ft_vm_instr_jump(t_champion *champ)
{
	int		i;

	i = 0;
	while (i < champ->instr.op->nb_args)
	{
		if (BYTECODE_GET(champ->instr.bytecode, i + 1) == IND_CODE)
		{
			DEBUG_MODE ? ft_printf("T_IND\n") : 0;
			champ->instr.jump += 2;
			champ->arg_types[i] = T_IND;
		}
		else if (BYTECODE_GET(champ->instr.bytecode, i + 1) == REG_CODE)
		{
			DEBUG_MODE ? ft_printf("T_REG\n") : 0;
			champ->instr.jump += 1;
			champ->arg_types[i] = T_REG;
		}
		else if (BYTECODE_GET(champ->instr.bytecode, i + 1) == DIR_CODE)
		{
			DEBUG_MODE ? ft_printf("T_DIR\n") : 0;
			champ->instr.jump += g_direct_jump_table_from_instr[champ->instr.op->numero];
			champ->arg_types[i] = T_DIR;
		}
		++i;
	}
	DEBUG_MODE ? ft_printf("jump : %d\n", champ->instr.jump) : 0;
}
