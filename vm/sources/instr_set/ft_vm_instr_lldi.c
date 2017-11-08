/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_lldi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:30:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/08 12:57:03 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : presentation
// TODO : carry

extern uint8_t g_direct_jump_table_from_instr[17];

void				ft_vm_instr_lldi(unsigned char arena[],
									t_dead_pool *dead_pool,
									t_champion *champ)
{
	int					i;
	unsigned int		value_to_load;
	unsigned char		*ptr;

	(void)dead_pool;
	ptr = champ->pc + 2;
	value_to_load = 0;
	i = 0;
	while (i < (champ->instr.op->nb_args - 1))
	{
		if (champ->instr.op->arg_types[i] == T_REG)
			value_to_load += champ->reg[*ptr];
		else if (champ->instr.op->arg_types[i] == T_IND)
		{
			value_to_load += arena[MOD((champ->pc - arena)
								+ ft_instruction_get_data(2, ptr))];
		}
		else if (champ->instr.op->arg_types[i] == T_DIR)
		{
			value_to_load += arena[
				MOD(ft_instruction_get_data(
				g_direct_jump_table_from_instr[champ->instr.op->numero], ptr))];
		}
		++i;
		ptr += champ->instr.arg_jump[i];
	}
	champ->reg[*ptr] = value_to_load;
}
