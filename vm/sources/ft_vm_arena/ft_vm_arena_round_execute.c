/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_round_execute.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:12:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/22 18:25:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

#ifndef CHAMP_DONE
# define CHAMP_DONE (dead_pool->champ[0].done + dead_pool->champ[1].done + dead_pool->champ[2].done + dead_pool->champ[3].done)
#endif

/*
* brief      			Execute a battle round
*
* param arena			Memory dedicated to the Virtual Machine
* param dead_pool		t_dead_pool struct for the game
* param nb_champion		Number of alive champions in the arena
*/

void				ft_vm_arena_round_routine(unsigned char arena[2][MEM_SIZE],
											t_dead_pool * dead_pool,
											unsigned int *nb_champion)
{
	dead_pool->idx ^= dead_pool->idx;
	/* Loop until all the champions finish their round */
	while (CHAMP_DONE != *nb_champion)
	{
		if (dead_pool->option.fd[CHAMP_IDX] && !dead_pool->champ[CHAMP_IDX].done)
		{
			/* Set up the t_champ pointer */
			// on peut virer ca ?
			//dedicated->i_champ = &dead_pool->champ[CHAMP_IDX];
			/* Execute champion's routine if they haven't finished their round */
			ft_vm_arena_champion_routine(arena, dead_pool);
			/* Send a notification for the visual */
			//ft_vm_notif_round()
		}
		// DONE AND LIVE CHECK DONE IN FT_VM_ARENA
		++dead_pool->idx;
	}
}
