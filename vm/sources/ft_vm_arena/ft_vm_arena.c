/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 21:51:40 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/16 16:24:32 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

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

#if 1
static void				ft_vm_arena_find_winner(t_dead_pool *dead_pool)
{
	dead_pool->idx ^= dead_pool->idx;
	while (dead_pool->idx < MAX_PLAYERS)
	{
		if (dead_pool->champ[dead_pool->idx].pc)
			return ;
		++dead_pool->idx;
	}
	#if 0
	if (dead_pool->champion1.pc)
	{
		dead_pool->i_champ = &dead_pool->champion1;
		dead_pool->i_champ->index = 1;
	}
	else if (dead_pool->champion2.pc)
	{
		dead_pool->i_champ = &dead_pool->champion2;
		dead_pool->i_champ->index = 2;
	}
	else if (dead_pool->champion3.pc)
	{
		dead_pool->i_champ = &dead_pool->champion3;
		dead_pool->i_champ->index = 3;
	}
	else if (dead_pool->champion4.pc)
	{
		dead_pool->i_champ = &dead_pool->champion4;
		dead_pool->i_champ->index = 4;
	}
	#endif
}
#endif

void					ft_vm_arena(unsigned char arena[MEM_SIZE],
	 								int option[],
									t_dead_pool *dead_pool,
									int *nb_champion)
{
	//unsigned int		current_cycle;
	unsigned int		cycle_to_die;

	cycle_to_die = CYCLE_TO_DIE;
	//cycle_to_die = 100;
	dead_pool->current_cycle = cycle_to_die;
	ft_vm_arena_upload_champion(arena, option, dead_pool, nb_champion);
	ft_vm_print_arena((void *)arena, MEM_SIZE, 64, dead_pool);
	while (*nb_champion != 1)
	{
		if (ft_vm_instr(arena, dead_pool, nb_champion) == EXIT_SUCCESS)
			break;
		ft_vm_arena_live_check(dead_pool, nb_champion);
		if (cycle_to_die > CYCLE_DELTA)
			cycle_to_die -= CYCLE_DELTA;
		else
			break ;
		dead_pool->current_cycle += cycle_to_die;
		//getchar();
	}
	// TODO: find winner can be removed
	ft_vm_arena_find_winner(dead_pool);
	ft_printf("Player %d ({green:%s}) won\n", dead_pool->idx, dead_pool->champ[dead_pool->idx].header.prog_name);
}
