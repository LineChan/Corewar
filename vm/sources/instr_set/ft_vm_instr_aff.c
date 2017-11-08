/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_aff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:34:23 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/08 12:57:06 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : presentation
// TODO : carry

void 			ft_vm_instr_aff(unsigned char arena[],
									t_dead_pool *dead_pool,
									t_champion *champ)
{
	DEBUG_MODE ? ft_printf("{yellow:aff}\n") : 0;
	(void)arena;
	(void)dead_pool;
	ft_printf("%c\n", (champ->reg[*(champ->pc + 2)] % 256));
}
