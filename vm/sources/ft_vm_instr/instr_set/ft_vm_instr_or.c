/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_or.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:29:36 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/16 21:22:00 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : presentation
/*
* brief      		Execute or : Apply an | (bit-to-bit OR) over the first
* two arguments and store the result in a registry, which is the third argument. It will change the carry.
*
* param arena
* param champ
*/
//TODO : carry
//TODO : remove libc.h
#include <libc.h>

void			ft_vm_instr_or(unsigned char arena[], t_dead_pool *dead_pool)
{
	int					i;
	unsigned int		or[2];
	unsigned char		*ptr;
	extern uint8_t		g_direct_jump_table_from_instr[17];

	/* Set up a pointer at the beginning of the arguments */
	ptr = dead_pool->i_champ->pc + 2;
	i = 0;
	DEBUG_MODE ? ft_printf("{yellow:or}\n") : 0;
	/* Read arguments */
	while (i < (dead_pool->i_champ->instr.op->nb_args - 1))
	{
		if (dead_pool->i_champ->instr.op->arg_types[i] == T_REG)
		{
			if (!IS_REG(*ptr))
			{
				dead_pool->i_champ->pc += 1;
				dead_pool->i_champ->next_cycle += 1;
				dead_pool->i_champ->carry = 1;
				return ;
			}
			or[i] = dead_pool->i_champ->reg[*ptr];
		}
		else if (dead_pool->i_champ->instr.op->arg_types[i] == T_IND)
			or[i] = arena[MOD(dead_pool->i_champ->pc - arena + ft_instruction_get_data(2, ptr))];
		else
			or[i] = arena[MOD(ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero], ptr))];
		ptr += dead_pool->i_champ->instr.arg_jump[i];
		++i;
	}
	/* Compute the result and load it in a register */
	if (IS_REG(*ptr))
	{
		dead_pool->i_champ->reg[*ptr] = or[0] | or[1];
		/* Move the Program Counter */
		dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0] + dead_pool->i_champ->instr.arg_jump[1] + dead_pool->i_champ->instr.arg_jump[2];
		/* Waiting time until the next instruction */
		dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
		/* Change the carry */
		dead_pool->i_champ->carry = 0;
	}
	else
	{
		dead_pool->i_champ->next_cycle += 1;
		dead_pool->i_champ->pc += 1;
		dead_pool->i_champ->carry = 1;
	}

	if (DEBUG_MODE)
	{
		ft_fprintf(2, "reg[%c] : or[0] : %d or[1] : %d ----> & %d \n", *ptr, or[0] , or[1], or[0] | or[1]);
		ft_vm_print_reg(&dead_pool->champ[CHAMP_IDX]);
	}
}
