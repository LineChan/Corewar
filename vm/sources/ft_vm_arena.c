/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 21:51:40 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/04 17:27:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/*
* brief      		Set up the virtual machine
*
* param arena		Memory dedicated to the virtual machine
* param option		Options' array
* param dead_pool	Structure gatehering all the champions
* param nb_champion	Champions number
*/
	// TODO : remove libc.h
#include <libc.h>

void		ft_vm_arena(unsigned char arena[MEM_SIZE],
	 							int option[],
								t_dead_pool *dead_pool,
								int *nb_champion)
{
	int			current_cycle;
	int			cycle_to_die;

	cycle_to_die = CYCLE_TO_DIE;
	current_cycle = cycle_to_die;
	ft_memset(arena, 0, MEM_SIZE);
	if (TEST_MODE)
	{
		int i = MEM_SIZE - 1;
		int nb = 1;
		while (i > (MEM_SIZE - 129))
		{
			arena[i] = nb;
			++nb;
			--i;
		}
	}

	ft_vm_arena_upload_champion(arena, option, dead_pool, nb_champion);
	ft_vm_print_arena((void *)arena, MEM_SIZE, 64, dead_pool);
	int i = 0;
	while (i < 2)
	{
		ft_vm_instr(arena, dead_pool, *nb_champion, current_cycle);
		ft_vm_print_arena((void *)arena, MEM_SIZE, 64, dead_pool);
		cycle_to_die -= CYCLE_DELTA;
		current_cycle += cycle_to_die;
		++i;
	}
}
