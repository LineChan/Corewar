/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 21:51:40 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/18 18:59:06 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

/*
* brief      		Set up the virtual machine
*
* param arena		Memory dedicated to the virtual machine
* param option		Options' array
* param dead_pool	Structure gatehering all the champions
* param nb_champion	Champions' number
*/

// TODO : remove libc.h
#include <libc.h>

static void				ft_vm_arena_find_winner(t_dead_pool *dead_pool)
{
	dead_pool->idx ^= dead_pool->idx;
	while (dead_pool->idx < MAX_PLAYERS)
	{
		if (dead_pool->champ[dead_pool->idx].pc)
			return ;
		++dead_pool->idx;
	}
}

void					ft_vm_arena(unsigned char arena[MEM_SIZE],
	 								int option[],
									t_dead_pool *dead_pool,
									unsigned int *nb_champion)
{
	unsigned int		cycle_to_die;

	cycle_to_die = CYCLE_TO_DIE;
	dead_pool->current_cycle = cycle_to_die;
	/* Place champions on the arena at the right position and set them up */
	/* for the battle */
	ft_vm_arena_upload_champion(arena, option, dead_pool, nb_champion);
	ft_vm_print_arena((void *)arena, MEM_SIZE, 64, dead_pool);
	/* If it doesn't exist, create a logfile and print a header */
	OPTION_LOG ? ft_vm_log_start(dead_pool, option) : 0;
	/* Main loop : the game is on until there is only one champion left */
	while (*nb_champion != 1)
	{
		/* Execute all instructions until the next cycle to die */
		ft_vm_instr(arena, option, dead_pool, nb_champion);
		/* Remove the champions who did not execute live since the last cycle to die */
		ft_vm_arena_live_check(dead_pool, nb_champion);
		/* Update the cycle to die and add it to the next_cycle to check in the arena */
		if (cycle_to_die > CYCLE_DELTA)
			cycle_to_die -= CYCLE_DELTA;
		else
			break ;
		dead_pool->current_cycle += cycle_to_die;
	}
	ft_log_close();
	ft_vm_arena_find_winner(dead_pool);
	ft_printf("Player %d ({green:%s}) won !\n", dead_pool->idx + 1, dead_pool->champ[dead_pool->idx].header.prog_name);
}
