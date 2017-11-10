/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:21:08 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/10 15:53:24 by mvillemi         ###   ########.fr       */
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
//TODO : carry

void 			ft_vm_instr_add(unsigned char arena[], t_dead_pool *dead_pool)
{
	int					i;
	unsigned int		add[3];
	unsigned char		*ptr;

	ptr = dead_pool->i_champ->pc + 2;
	i = 0;
	DEBUG_MODE ? ft_printf("{yellow:add}\n") : 0;
	(void)arena;
	while (i < dead_pool->i_champ->instr.op->nb_args)
	{
		add[i] = *ptr;
		++ptr;
		++i;
	}
	if (IS_REG(add[0]) && IS_REG(add[1]) && IS_REG(add[2]))
	{
		dead_pool->i_champ->reg[add[2]] = dead_pool->i_champ->reg[add[0]]
												+ dead_pool->i_champ->reg[add[1]];
		dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0] +
										dead_pool->i_champ->instr.arg_jump[1]
										+ dead_pool->i_champ->instr.arg_jump[2];
		dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
	}
	else
		dead_pool->i_champ->pc += 1;

	if (DEBUG_MODE)
	{
		ft_printf("add[0] : %d\n", add[0]);
		ft_printf("add[1] : %d\n", add[1]);
		ft_printf("add[2] : %d\n\n", add[2]);
		ft_vm_print_reg(dead_pool->i_champ);
		getchar();
	}
}
