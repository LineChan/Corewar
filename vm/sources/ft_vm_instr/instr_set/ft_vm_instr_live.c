/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_live.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:25:20 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/16 10:08:23 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
//TODO: presentation

//TODO : remove libc.h
#include <libc.h>

void           ft_vm_instr_live(unsigned char arena[], t_dead_pool *dead_pool)
{
	int				number;

	ft_printf("live %s\n", dead_pool->i_champ->header.prog_name);
	(void)arena;
	number = ft_instruction_get_data(4, dead_pool->i_champ->pc + 1);
	if (number == 1)
		++dead_pool->champ[0].live;
	else if (number == 2)
		++dead_pool->champ[1].live;
	else if (number == 3)
		++dead_pool->champ[2].live;
	else if (number == 4)
		++dead_pool->champ[3].live;

	dead_pool->i_champ->pc += 5;
	getchar();
}
