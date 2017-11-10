/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_lldi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:30:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/10 15:47:23 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : presentation
// TODO : carry

extern uint8_t g_direct_jump_table_from_instr[17];

void			ft_vm_instr_lldi(unsigned char arena[], t_dead_pool *dead_pool)
{
	int					i;
	unsigned int		value_to_load;
	unsigned char		*ptr;

	ptr = dead_pool->i_champ->pc + 2;
	value_to_load = 0;
	i = 0;
	while (i < (dead_pool->i_champ->instr.op->nb_args - 1))
	{
		if (dead_pool->i_champ->instr.op->arg_types[i] == T_REG)
		{
			if (!IS_REG(*ptr))
			{
				dead_pool->i_champ->pc += 1;
				return ;
			}
			value_to_load += dead_pool->i_champ->reg[*ptr];
		}
		else if (dead_pool->i_champ->instr.op->arg_types[i] == T_IND)
		{
			value_to_load += arena[MOD(dead_pool->i_champ->pc - arena
								+ ft_instruction_get_data(2, ptr))];
		}
		else if (dead_pool->i_champ->instr.op->arg_types[i] == T_DIR)
		{
			value_to_load += arena[
				MOD(ft_instruction_get_data(
				g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero], ptr))];
		}
		++i;
		ptr += dead_pool->i_champ->instr.arg_jump[i];
	}
	if (IS_REG(*ptr))
	{
		dead_pool->i_champ->reg[*ptr] = value_to_load;
		dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0]
									+ dead_pool->i_champ->instr.arg_jump[1]
									+ dead_pool->i_champ->instr.arg_jump[2];
		dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
	}
	else
		dead_pool->i_champ->pc += 1;
}
