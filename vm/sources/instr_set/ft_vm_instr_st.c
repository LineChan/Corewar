/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_st.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 20:32:54 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/07 17:46:45 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
	//TODO : presentation
extern uint8_t g_direct_jump_table_from_instr[17];
/*
* brief      		Execute ld : Take a registry and a registry or an indirect
* and store the value of the registry toward a second argument
*
* param arena
* param champ
*/

//TODO : remove libc.h
#include <libc.h>

void				ft_vm_instr_st(unsigned char arena[],
									t_dead_pool *dead_pool,
									t_champion *champ)
{
	if (champ->instr.op->arg_types[1] == T_REG)
		champ->reg[*(champ->pc + 3)] = champ->reg[*(champ->pc + 2)];
	else
		arena[MOD((champ->pc - arena) + (ft_instruction_get_data(2, champ->pc + 3)))] = champ->reg[*(champ->pc + 2)];
	champ->pc += 2 + champ->instr.arg_jump[0] + champ->instr.arg_jump[1];

	if (DEBUG_MODE)
	{
		ft_printf("{yellow:st}\n");
		ft_printf("reg[0] : %d\n", champ->reg[0]);
		ft_printf("reg[1] : %d\n", champ->reg[1]);
		ft_printf("reg[2] : %d\n", champ->reg[2]);
		ft_printf("reg[3] : %d\n", champ->reg[3]);
		ft_printf("reg[4] : %d\n", champ->reg[4]);
		ft_printf("reg[5] : %d\n", champ->reg[5]);
		ft_printf("reg[6] : %d\n", champ->reg[6]);
		ft_printf("reg[7] : %d\n", champ->reg[7]);
		ft_printf("reg[8] : %d\n", champ->reg[8]);
		ft_printf("reg[9] : %d\n", champ->reg[9]);
		ft_printf("reg[10] : %d\n", champ->reg[10]);
		ft_printf("reg[11] : %d\n", champ->reg[11]);
		getchar();
		ft_vm_print_arena((void *)arena, MEM_SIZE, 64, dead_pool);
	}
}
