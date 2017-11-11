/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_aff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:34:23 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/10 22:22:51 by mvillemi         ###   ########.fr       */
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
	if (IS_REG(*(dead_pool->i_champ->pc + 2)))
	{
		ft_printf("%c\n", (dead_pool->i_champ->reg[*(dead_pool->i_champ->pc + 2)] % 256));
		/* Move the Pointer Counter */
		dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0];
	}
	else
		dead_pool->i_champ->pc += 1;
}
