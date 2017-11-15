/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:21:08 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/15 17:22:33 by mvillemi         ###   ########.fr       */
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
	#if 0
	int					i;
	unsigned int		add[3];
	unsigned char		*ptr;

	/* Set up a pointer at the beginning of the arguments */
	ptr = dead_pool->champ[CHAMP_IDX].pc + 2;
	i = 0;
	DEBUG_MODE ? ft_printf("{yellow:add}\n") : 0;
	(void)arena;
	/* Store arguments */
	while (i < dead_pool->champ[CHAMP_IDX].instr.op->nb_args)
	{
		add[i] = *ptr;
		++ptr;
		++i;
	}
	/* Check if it is a register number */
	if (IS_REG(add[0]) && IS_REG(add[1]) && IS_REG(add[2]))
	{
		dead_pool->champ[CHAMP_IDX].reg[add[2]] = dead_pool->champ[CHAMP_IDX].reg[add[0]]
												+ dead_pool->champ[CHAMP_IDX].reg[add[1]];
		/* Move the Pointer Counter */
		dead_pool->champ[CHAMP_IDX].pc += 2 + dead_pool->champ[CHAMP_IDX].instr.arg_jump[0] +
										dead_pool->champ[CHAMP_IDX].instr.arg_jump[1]
										+ dead_pool->champ[CHAMP_IDX].instr.arg_jump[2];
	}
	else
		dead_pool->champ[CHAMP_IDX].pc += 1;

	if (DEBUG_MODE)
	{
		ft_printf("add[0] : %d\n", add[0]);
		ft_printf("add[1] : %d\n", add[1]);
		ft_printf("add[2] : %d\n\n", add[2]);
		ft_vm_print_reg(&dead_pool->champ[CHAMP_IDX]);
		getchar();
	}
	#endif
	#if 1
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
		dead_pool->i_champ->reg[add[2]] = dead_pool->i_champ->reg[add[0]]
												+ dead_pool->i_champ->reg[add[1]];
		/* Move the Pointer Counter */
		dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0] +
										dead_pool->i_champ->instr.arg_jump[1]
										+ dead_pool->i_champ->instr.arg_jump[2];
	}
	else
		dead_pool->i_champ->pc += 1;

	if (DEBUG_MODE)
	{
		ft_fprintf(2, "add[0] : %d\n", add[0]);
		ft_fprintf(2, "add[1] : %d\n", add[1]);
		ft_fprintf(2, "add[2] : %d\n\n", add[2]);
		ft_vm_print_reg(dead_pool->i_champ);
		getchar();
	}
	#endif
}
