/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:21:08 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/18 23:46:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

/*
* brief      		Execute add : Take three registries, add the first two,
*					and place the result in the third, right before modifying the carry.
*
* param arena
* param champ
*/
//TODO : remove libc.h
#include <libc.h>

void 			ft_vm_instr_add(unsigned char arena[],
								t_dead_pool *dead_pool,
								int option[])
{
	int					i;
	unsigned int		add[3];
	unsigned char		*ptr;

	/* Set up a pointer at the beginning of the arguments */
	ptr = dead_pool->i_champ->pc + 2;
	i = 0;
	DEBUG_MODE ? ft_printf("{yellow:add}\n") : 0;
	(void)arena;
	/* Store arguments */
	while (i < dead_pool->i_champ->instr.op->nb_args)
	{
		add[i] = *ptr;
		++ptr;
		++i;
	}
	/* Check if it is a register number */
	if (IS_REG(add[0]) && IS_REG(add[1]) && IS_REG(add[2]))
	{
		dead_pool->i_champ->reg[add[2]] = MOD(dead_pool->i_champ->reg[add[0]]
												+ dead_pool->i_champ->reg[add[1]]);
		/* Move the Pointer Counter */
		dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0] +
										dead_pool->i_champ->instr.arg_jump[1]
										+ dead_pool->i_champ->instr.arg_jump[2];
		OPTION_LOG ? ft_vm_log_add(dead_pool, add) : 0;
		/* Waiting time until the next instrution */
		dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
		/* Change the carry */
		dead_pool->i_champ->carry = 0;
	}
	else
	{
		dead_pool->i_champ->pc += 1;
		dead_pool->i_champ->next_cycle += 1;
		dead_pool->i_champ->carry = 1;
	}
	DEBUG_MODE ? ft_vm_print_reg(dead_pool->i_champ) : 0;
}
