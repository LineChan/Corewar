/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:21:08 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/08 12:57:05 by mvillemi         ###   ########.fr       */
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

void 			ft_vm_instr_add(unsigned char arena[],
								t_dead_pool *dead_pool,
								t_champion *champ)
{
	int					i;
	unsigned int		add[3];
	unsigned char		*ptr;

	ptr = champ->pc + 2;
	i = 0;
	DEBUG_MODE ? ft_printf("{yellow:add}\n") : 0;
	(void)dead_pool;
	(void)arena;
	while (i < champ->instr.op->nb_args)
	{
		add[i] = *ptr;
		++ptr;
		++i;
	}
	champ->reg[add[2]] = champ->reg[add[0]] + champ->reg[add[1]];
	champ->pc += 2 + champ->instr.arg_jump[0] + champ->instr.arg_jump[1] + champ->instr.arg_jump[2];
	if (DEBUG_MODE)
	{
		ft_printf("add[0] : %d\n", add[0]);
		ft_printf("add[1] : %d\n", add[1]);
		ft_printf("add[2] : %d\n\n", add[2]);
		ft_vm_print_reg(champ);
		getchar();
	}
}
