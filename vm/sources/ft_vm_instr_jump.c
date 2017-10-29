/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_jump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 01:24:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/29 20:59:54 by mvillemi         ###   ########.fr       */
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

static void 			ft_vm_instr_save(t_champion *champ, int arg_nb, int type, int size)
{
	champ->instr.jump += size;
	champ->arg_types[arg_nb] = type;
}

void			ft_vm_instr_jump(t_champion *champ)
{
	if (BYTECODE_GET(champ->instr.bytecode, 1) == IND_CODE)
		ft_vm_instr_save(champ, 0, T_IND, IND_SIZE);
	else if (BYTECODE_GET(champ->instr.bytecode, 1) == REG_CODE)
		ft_vm_instr_save(champ, 0, T_REG, REG_SIZE);
	else if (BYTECODE_GET(champ->instr.bytecode, 1) == DIR_CODE)
		ft_vm_instr_save(champ, 0, T_DIR, g_direct_jump_table_from_instr[champ->instr.index]);
	//ft_printf("jump : %d\n", champ->instr.jump);
	if (BYTECODE_GET(champ->instr.bytecode, 2) == IND_CODE)
		ft_vm_instr_save(champ, 1, T_IND, IND_SIZE);
	else if (BYTECODE_GET(champ->instr.bytecode, 2) == REG_CODE)
		ft_vm_instr_save(champ, 1, T_REG, REG_SIZE);
	else if (BYTECODE_GET(champ->instr.bytecode, 2) == DIR_CODE)
		ft_vm_instr_save(champ, 1, T_DIR, g_direct_jump_table_from_instr[champ->instr.index]);
	//ft_printf("jump : %d\n", champ->instr.jump);
	if (BYTECODE_GET(champ->instr.bytecode, 3) == IND_CODE)
		ft_vm_instr_save(champ, 2, T_IND, IND_SIZE);
	else if (BYTECODE_GET(champ->instr.bytecode, 3) == REG_CODE)
		ft_vm_instr_save(champ, 2, T_REG, REG_SIZE);
	else if (BYTECODE_GET(champ->instr.bytecode, 3) == DIR_CODE)
		ft_vm_instr_save(champ, 2, T_DIR, g_direct_jump_table_from_instr[champ->instr.index]);
	//ft_printf("jump : %d\n", champ->instr.jump);
}
