/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_ld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:49:07 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/04 18:15:21 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
// TODO: presentation

extern uint8_t g_direct_jump_table_from_instr[17];
/*
* brief      		Execute ld : Take a random argument and a registry.
* Load the value of the first argument in the registry. It will change the carry.
*
* param arena
* param champ
*/
//TODO : do the carry change

void			ft_vm_instr_ld(unsigned char arena[],
								t_dead_pool *dead_pool,
								t_champion *champ)
{
	DEBUG_MODE ? ft_printf("{yellow:ld}\n") : 0;
	unsigned char		*ptr;
	unsigned int		value_to_load;

	(void)dead_pool;
	(void)arena;
	ptr = champ->pc + 2;
	// NB : result not good
	if (champ->instr.op->arg_types[0] == T_DIR)
		value_to_load = ft_instruction_get_data(g_direct_jump_table_from_instr[champ->instr.op->numero], ptr);
	else
		value_to_load = ft_instruction_get_data(2, ptr);
	champ->pc += champ->instr.arg_jump[0];
	champ->reg[*ptr] = value_to_load;
	if (DEBUG_MODE)
	{
		ft_printf("reg[%c] : %d\n", *ptr, value_to_load);
		ft_printf("champ->reg[0] : %d\n", champ->reg[0]);
		ft_printf("champ->reg[1] : %d\n", champ->reg[1]);
		ft_printf("champ->reg[2] : %d\n", champ->reg[2]);
		ft_printf("champ->reg[3] : %d\n", champ->reg[3]);
		ft_printf("champ->reg[4] : %d\n", champ->reg[4]);
		ft_printf("champ->reg[5] : %d\n", champ->reg[5]);
		ft_printf("champ->reg[6] : %d\n", champ->reg[6]);
		ft_printf("champ->reg[7] : %d\n", champ->reg[7]);
		ft_printf("champ->reg[8] : %d\n", champ->reg[8]);
		ft_printf("champ->reg[9] : %d\n", champ->reg[9]);
		ft_printf("champ->reg[10] : %d\n", champ->reg[10]);
		ft_printf("champ->reg[11] : %d\n", champ->reg[11]);
		ft_printf("champ->reg[12] : %d\n", champ->reg[12]);
		ft_printf("champ->reg[13] : %d\n", champ->reg[13]);
		ft_printf("champ->reg[14] : %d\n", champ->reg[14]);
		ft_printf("champ->reg[15] : %d\n", champ->reg[15]);
	}
}
