/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:08:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/11 17:06:21 by mvillemi         ###   ########.fr       */
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
# define CHAMP_DONE (dead_pool->champion1.done + dead_pool->champion2.done + dead_pool->champion3.done + dead_pool->champion4.done)
#endif
#include <libc.h>

void				ft_vm_instr_init_done(t_dead_pool *dead_pool)
{
	dead_pool->champion1.done ^= dead_pool->champion1.done;
	dead_pool->champion2.done ^= dead_pool->champion2.done;
	dead_pool->champion3.done ^= dead_pool->champion3.done;
	dead_pool->champion4.done ^= dead_pool->champion4.done;

	if (DEBUG_MODE)
	{
		ft_fprintf(2, "dead_pool->champion1.done : %d\n",dead_pool->champion1.done);
		ft_fprintf(2, "dead_pool->champion2.done : %d\n",dead_pool->champion2.done);
		ft_fprintf(2, "dead_pool->champion3.done : %d\n",dead_pool->champion3.done);
		ft_fprintf(2,	 "dead_pool->champion4.done : %d\n",dead_pool->champion4.done);
	}
}

int						ft_vm_instr(unsigned char arena[],
										t_dead_pool *dead_pool,
										int *nb_champion,
										unsigned const int current_cycle)
{
	int			i;

	i = 0;
	dead_pool->i_champ = &dead_pool->champion1;
	while (i < MAX_PLAYERS)
	{
		if ((dead_pool->i_champ->pc) && !dead_pool->i_champ->done)
		{
			ft_printf("going to routine\n");
			//if (dead_pool->i_champ->next_cycle <= current_cycle)
			{
				ft_vm_instr_champion_routine(arena, dead_pool, current_cycle);
				ft_printf("vm_instr next_cycle : %d current : %d\n", dead_pool->i_champ->next_cycle, current_cycle);
				if (dead_pool->i_champ->next_cycle > current_cycle)
				{
					dead_pool->i_champ->done = 1;
					if (EXIT_SUCCESS == ft_vm_instr_end_of_game(dead_pool, nb_champion))
						return (EXIT_SUCCESS);
				}
				getchar();
			}
		}
		++dead_pool->i_champ;
		++i;
		if (MAX_PLAYERS == i)
		{
			i ^= i;
			dead_pool->i_champ = &dead_pool->champion1;
			if (CHAMP_DONE == (unsigned int)*nb_champion)
			{
				ft_printf("{red:turn is over}\n");
				return (EXIT_FAILURE);
			}
			getchar();
		}
	}
	return (EXIT_FAILURE);
}
