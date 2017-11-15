/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_ldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:32:54 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/15 17:26:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : presentation
// TODO : carry

extern uint8_t g_direct_jump_table_from_instr[17];

void			ft_vm_instr_ldi(unsigned char arena[], t_dead_pool *dead_pool)

{
	int					i;
	unsigned int		value_to_load;
	unsigned char		*ptr;

	/* Set a pointer at the beginning of the arguments */
	ptr = dead_pool->i_champ->pc + 2;
	value_to_load = 0;
	i = 0;
	/* Read arguments */
	while (i < (dead_pool->i_champ->instr.op->nb_args - 1))
	{
		if (dead_pool->i_champ->instr.op->arg_types[i] == T_REG)
		{
			if (IS_REG(*ptr))
				value_to_load += dead_pool->i_champ->reg[*ptr];
			else
			{
				dead_pool->i_champ->pc += 1;
				return ;
			}
		}
		else if (dead_pool->i_champ->instr.op->arg_types[i] == T_IND)
			value_to_load += arena[MOD((dead_pool->i_champ->pc - arena)
							+ (ft_instruction_get_data(2, ptr) % IDX_MOD))];
		else if (dead_pool->i_champ->instr.op->arg_types[i] == T_DIR)
			value_to_load += arena[MOD(ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero], ptr))];
		++i;
		ptr += dead_pool->i_champ->instr.arg_jump[i];
	}
	/* Load the value in a register */
	if (IS_REG(*ptr))
	{
		dead_pool->i_champ->reg[*ptr] = value_to_load;
		/* Move the Program Counter */
		dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0]
									+ dead_pool->i_champ->instr.arg_jump[1]
									+ dead_pool->i_champ->instr.arg_jump[2];
	}
	else
		dead_pool->i_champ->pc += 1;

}
