/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_live.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:25:20 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/18 20:21:25 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
//TODO: presentation

//TODO : remove libc.h
#include <libc.h>

void           ft_vm_instr_live(unsigned char arena[],
									t_dead_pool *dead_pool,
									int option[])
{
	int				number;
	extern			uint8_t g_direct_jump_table_from_instr[17];

	ft_printf("live %s\n", dead_pool->i_champ->header.prog_name);
	(void)arena;
	number = ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero], dead_pool->i_champ->pc + 1);
	if (number == 1)
		++dead_pool->champ[0].live;
	else if (number == 2)
		++dead_pool->champ[1].live;
	else if (number == 3)
		++dead_pool->champ[2].live;
	else if (number == 4)
		++dead_pool->champ[3].live;
	/* Move the Program Counter */
	dead_pool->i_champ->pc += 1 + g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero];
	/* Write log */
	OPTION_LOG ? ft_vm_log_live(dead_pool, number) : 0;
	/* Waiting time until the next instruction */
	dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
}
