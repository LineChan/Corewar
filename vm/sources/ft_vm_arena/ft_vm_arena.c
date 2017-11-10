/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 21:51:40 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/10 12:15:59 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

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
}

void					ft_vm_arena(unsigned char arena[MEM_SIZE],
	 								int option[],
									t_dead_pool *dead_pool,
									int *nb_champion)
{
	unsigned int		current_cycle;
	unsigned int		cycle_to_die;

	cycle_to_die = CYCLE_TO_DIE;
	//cycle_to_die = 10;
	current_cycle = cycle_to_die;

	ft_vm_arena_upload_champion(arena, option, dead_pool, nb_champion);
	ft_vm_print_arena((void *)arena, MEM_SIZE, 64, dead_pool);

	//while (1)
	{
		ft_vm_instr(arena, dead_pool, *nb_champion, current_cycle);
		ft_vm_arena_live_check(dead_pool, nb_champion);
		getchar();
	}
	#if 0
	while (*nb_champion != 1)
	{
		ft_vm_instr(arena, dead_pool, *nb_champion, current_cycle);
		ft_vm_arena_live_check(dead_pool, nb_champion);
		ft_printf("ft_vm_arena : nb_champion = %d\n", *nb_champion);
		getchar();
	}
	ft_vm_arena_find_winner(dead_pool);
	ft_printf("Player %d ({green:%s}) won\n", dead_pool->i_champ->index, dead_pool->i_champ->header.prog_name);
	#endif
	ft_vm_arena_find_winner(dead_pool);
}
