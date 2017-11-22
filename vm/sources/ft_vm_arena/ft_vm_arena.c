/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 21:51:40 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/22 18:28:42 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

/*
* brief      			Set up the Virtual Machine orchestrate the battle
*
* param arena			Memory dedicated to the Virtual Machine
* param dead_pool		t_dead_pool struct for the game
* param nb_champion		Number of alive champions in the arena
*/

#if 0
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
#endif

void					ft_vm_arena(unsigned char arena[2][MEM_SIZE],
									t_dead_pool *dead_pool,
									unsigned int *nb_champion)
{
	(void)arena;
	(void)dead_pool;
	(void)nb_champion;
	unsigned int		cycle_to_die;

	ft_memset((void *)arena, 0, MEM_SIZE);
	cycle_to_die = CYCLE_TO_DIE;
	dead_pool->current_cycle = cycle_to_die;
	/* Place champions on the arena at the right position and set them up */
	/* for the battle */
	ft_printf("{red:SEGFAULT}\n");
	ft_vm_arena_upload_champion(arena, dead_pool, nb_champion);
	/* If it doesn't exist, create the logfile and print its header */
	OPTION_LOG ? ft_vm_log_introduction(dead_pool) : 0;
	/* Main loop : the game is on until there is only one champion left */
	while (*nb_champion != 1)
	{
		/* Execute all instruction until the next cycle to die */
		ft_vm_arena_round_routine(arena, dead_pool, nb_champion);
		/* Check for living champion and update the next cycle to die */
		//ft_vm_arena_round_check();
	// ft_log_close();
	// find winner ?
	// ft_print_winner
	}
}
	#if 0
	unsigned int		cycle_to_die;

	cycle_to_die = CYCLE_TO_DIE;
	dead_pool->current_cycle = cycle_to_die;
	/* Place champions on the arena at the right position and set them up */
	/* for the battle */
	ft_vm_print_arena((void *)arena, MEM_SIZE, 64, dead_pool);


	/* If it doesn't exist, create a logfile and print a header */
	OPTION_LOG ? ft_vm_log_start(dead_pool) : 0;
	/* Main loop : the game is on until there is only one champion left */
	while (*nb_champion != 1)
	{
		#if 1
		/* Execute all instructions until the next cycle to die */
		ft_vm_instr(arena, option, dead_pool, nb_champion);
		/* Remove the champions who did not execute live since the last cycle to die */
		// ROUND_CHECK
		ft_vm_arena_live_check(dead_pool, nb_champion);
		/* Update the cycle to die and add it to the next_cycle to check in the arena */
		if (cycle_to_die > CYCLE_DELTA)
			cycle_to_die -= CYCLE_DELTA;
		else
			break ;
		dead_pool->current_cycle += cycle_to_die;
		#endif
	}
	ft_log_close();
	ft_vm_arena_find_winner(dead_pool);
	ft_printf("Player %d ({green:%s}) won !\n", dead_pool->idx + 1, dead_pool->champ[dead_pool->idx].header.prog_name);
	#endif
