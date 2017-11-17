/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_lldi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:30:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/17 16:32:25 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : presentation

// NB : value to load can be removed
void			ft_vm_instr_lldi(unsigned char arena[],
									t_dead_pool *dead_pool,
									int option[])
{
	int					i;
	unsigned int		value_to_load;
	unsigned char		*ptr;
	extern uint8_t		g_direct_jump_table_from_instr[17];

	/* Set up a pointer at the beginning of the arguments */
	ptr = dead_pool->i_champ->pc + 2;
	value_to_load = 0;
	i = 0;
	/* Read arguments */
	while (i < (dead_pool->i_champ->instr.op->nb_args - 1))
	{
		if (dead_pool->i_champ->instr.op->arg_types[i] == T_REG)
		{
			if (!IS_REG(*ptr))
			{
				dead_pool->i_champ->pc += 1;
				dead_pool->i_champ->next_cycle = 1;
				dead_pool->i_champ->carry = 1;
				return ;
			}
			value_to_load += dead_pool->i_champ->reg[*ptr];
		}
		else if (dead_pool->i_champ->instr.op->arg_types[i] == T_IND)
		{
			value_to_load += (arena[MOD(dead_pool->i_champ->pc - arena
								+ ft_instruction_get_data(2, ptr))]);
		}
		else if (dead_pool->i_champ->instr.op->arg_types[i] == T_DIR)
		{
			value_to_load += arena[(MOD(ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero], ptr)))];
		}
		++i;
		ptr += dead_pool->i_champ->instr.arg_jump[i];
	}
	/* Load a value in a register */
	if (IS_REG(*ptr))
	{
		dead_pool->i_champ->reg[*ptr] = value_to_load;
		/* Move the Program Counter */
		dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0]
									+ dead_pool->i_champ->instr.arg_jump[1]
									+ dead_pool->i_champ->instr.arg_jump[2];
		/* Waiting time until the next instruction */
		dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
		/* Change the carry */
		dead_pool->i_champ->carry = 0;
		if (OPTION_SUMMARY)
			ft_fprintf(OPTION_SUMMARY, "(%d) : lldi\n\tREG[%c] = %d\n", CHAMP_IDX + 1, *ptr, dead_pool->i_champ->reg[*ptr]);
	}
	else
	{
		dead_pool->i_champ->pc += 1;
		dead_pool->i_champ->next_cycle += 1;
		dead_pool->i_champ->carry = 1;
	}
}
