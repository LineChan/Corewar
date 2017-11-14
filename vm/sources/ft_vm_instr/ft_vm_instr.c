/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:08:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/14 16:09:58 by mvillemi         ###   ########.fr       */
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
	dead_pool->ixd ^= dead_pool->ixd;
	while (dead_pool->idx < MAX_PLAYERS)
	{
		dead_pool->champ[dead_pool->idx].done ^= dead_pool->champ[dead_pool->idx].done;
		++dead_pool->idx;
	}
	#if 0
	dead_pool->champion1.done ^= dead_pool->champion1.done;
	dead_pool->champion2.done ^= dead_pool->champion2.done;
	dead_pool->champion3.done ^= dead_pool->champion3.done;
	dead_pool->champion4.done ^= dead_pool->champion4.done;
	if (DEBUG_MODE)
	{
		ft_fprintf(2, "dead_pool->champion1.done : %d\n",dead_pool->champion1.done);
		ft_fprintf(2, "dead_pool->champion2.done : %d\n",dead_pool->champion2.done);
		ft_fprintf(2, "dead_pool->champion3.done : %d\n",dead_pool->champion3.done);
		ft_fprintf(2, "dead_pool->champion4.done : %d\n",dead_pool->champion4.done);
	}
	#endif

}

int						ft_vm_instr(unsigned char arena[],
										t_dead_pool *dead_pool,
										int *nb_champion,
										unsigned const int current_cycle)
{
	dead_pool->idx ^= dead_pool->idx;
	while (1)
	{
		ft_printf("\n{bblack:ft_vm_instr :} {yellow:%s} next_cycle : %d\n", dead_pool->champ[dead_pool->idx % MAX_PLAYERS]->header.prog_name, dead_pool->champ[dead_pool->idx % MAX_PLAYERS]->next_cycle);
		if (*dead_pool->champ[dead_pool->idx % MAX_PLAYERS]->header.prog_name)
		{
			if (dead_pool->champ[dead_pool->idx % MAX_PLAYERS]->next_cycle > current_cycle)
			{
				ft_vm_instr_champion_routine(arena, dead_pool, current_cycle);
				if (dead_pool->champ[dead_pool->idx % MAX_PLAYERS]->next_cycle > current_cycle)
				{
					dead_pool->champ[dead_pool->idx % MAX_PLAYERS]->done = 1;
					if (EXIT_SUCCESS == ft_vm_instr_end_of_game(dead_pool, nb_champion))
						return (EXIT_SUCCESS);
				}
			}
		}
		++dead_pool->idx;
		if (i && !(i % MAX_PLAYERS))
		{
			if (CHAMP_DONE == (unsigned int)*nb_champion)
			{
				ft_printf("{red:turn is over}\n");
				return(EXIT_FAILURE);
			}
		}
	}
	#if 0
	int			i;

	i = 0;
	dead_pool->i_champchamp[dead_pool->idx % MAX_PLAYERS] = &dead_pool->champion1;
	while (i < MAX_PLAYERS)
	{
		if (*dead_pool->i_champ->header.prog_name)
		{
			ft_printf("\n{bblack:ft_vm_instr :} {yellow:%s} next_cycle : %d\n", dead_pool->i_champ->header.prog_name, dead_pool->i_champ->next_cycle);


			if (dead_pool->i_champ->next_cycle <= current_cycle)
			{
				ft_vm_instr_champion_routine(arena, dead_pool, current_cycle);



				if (dead_pool->i_champ->next_cycle > current_cycle)
				{
					dead_pool->i_champ->done = 1;
					if (EXIT_SUCCESS == ft_vm_instr_end_of_game(dead_pool, nb_champion))
						return (EXIT_SUCCESS);
				}



			}



		}
		++dead_pool->i_champ;
		++i;
		if (i == MAX_PLAYERS)
		{
			i ^= i;
			dead_pool->i_champ = &dead_pool->champion1;
			if (CHAMP_DONE == (unsigned int)*nb_champion)
			{
				ft_printf("{red:turn is over}\n");
				return (EXIT_FAILURE);
			}
		}
	}
	return (EXIT_FAILURE);
	#endif
}
