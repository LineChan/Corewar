/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_aff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:34:23 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/14 23:32:46 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : presentation
// TODO : carry

void 			ft_vm_instr_aff(unsigned char arena[], t_dead_pool *dead_pool)
{
	DEBUG_MODE ? ft_printf("{yellow:aff}\n") : 0;
	(void)arena;
	/* Check if the number is a register number */
	if (IS_REG(*(dead_pool->champ[CHAMP_IDX].pc + 2)))
	{
		ft_printf("%c\n", (dead_pool->champ[CHAMP_IDX].reg[*(dead_pool->champ[CHAMP_IDX].pc + 2)] % 256));
		/* Move the Pointer Counter */
		dead_pool->champ[CHAMP_IDX].pc += 2 + dead_pool->champ[CHAMP_IDX].instr.arg_jump[0];
	}
	else
		dead_pool->champ[CHAMP_IDX].pc += 1;
	#if 0
	DEBUG_MODE ? ft_printf("{yellow:aff}\n") : 0;
	(void)arena;
	/* Check if the number is a register number */
	if (IS_REG(*(dead_pool->i_champ->pc + 2)))
	{
		ft_printf("%c\n", (dead_pool->i_champ->reg[*(dead_pool->i_champ->pc + 2)] % 256));
		/* Move the Pointer Counter */
		dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0];
	}
	else
		dead_pool->i_champ->pc += 1;
	#endif
}
