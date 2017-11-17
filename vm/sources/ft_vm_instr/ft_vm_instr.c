/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:08:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/17 15:03:11 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"
// TODO : presentation
/*
* brief      		Set up the virtual machine
*
* param arena		Memory dedicated to the virtual machine
* param option		Options' array
* param dead_pool	Structure gatehering all the champions
* param nb_champion	Champions' number
*/

// TODO : libc.h
#ifndef CHAMP_DONE
# define CHAMP_DONE (dead_pool->champ[0].done + dead_pool->champ[1].done + dead_pool->champ[2].done + dead_pool->champ[3].done)
#endif
#include <libc.h>

void				ft_vm_instr_init_done(t_dead_pool *dead_pool)
{
	dead_pool->idx ^= dead_pool->idx;
	while (dead_pool->idx < MAX_PLAYERS)
	{
		dead_pool->champ[dead_pool->idx].done ^= dead_pool->champ[dead_pool->idx].done;
		++dead_pool->idx;
	}
}

void						ft_vm_instr(unsigned char arena[],
										int option[],
										t_dead_pool *dead_pool,
										unsigned int *nb_champion)
{
	dead_pool->idx ^= dead_pool->idx;
	/* While all the champions haven't executed all their instructions */
	while (CHAMP_DONE != *nb_champion)
	{
		ft_printf("dead_pool->idx : %d\n", dead_pool->idx);
		if ((dead_pool->champ[CHAMP_IDX].pc)
				&& !dead_pool->champ[CHAMP_IDX].done)
		{
			ft_printf("\n{bblack:ft_vm_instr :} {yellow:%s} next_cycle : %d\n", dead_pool->champ[CHAMP_IDX].header.prog_name, dead_pool->champ[CHAMP_IDX].next_cycle);
			dead_pool->i_champ = &dead_pool->champ[CHAMP_IDX];
			/* Instruction execution routine per champion */
			ft_vm_instr_champion_routine(arena, dead_pool, option);
			/* If the champion has executed all its instructions */
			/* it is set as done and waits until the next cycle to die */
			ft_vm_instr_check_if_done(dead_pool);
		}
		ft_printf("{red:SEGFAULT OUT}\n");
		ft_vm_print_arena((void *)arena, MEM_SIZE, 64, dead_pool);
		getchar();
		++dead_pool->idx;
	}
}
