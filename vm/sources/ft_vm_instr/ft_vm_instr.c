/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:08:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/10 13:29:12 by mvillemi         ###   ########.fr       */
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
# define CHAMP_DONE (dead_pool->champion1.done + dead_pool->champion2.done + dead_pool->champion3.done + dead_pool->champion4.done)
#include <libc.h>

void				ft_vm_instr_init_done(t_dead_pool *dead_pool)
{
	dead_pool->champion1.done ^= dead_pool->champion1.done;
	dead_pool->champion2.done ^= dead_pool->champion2.done;
	dead_pool->champion3.done ^= dead_pool->champion3.done;
	dead_pool->champion4.done ^= dead_pool->champion4.done;

	ft_fprintf(2, "dead_pool->champion1.done : %d\n",dead_pool->champion1.done);
	ft_fprintf(2, "dead_pool->champion2.done : %d\n",dead_pool->champion2.done);
	ft_fprintf(2, "dead_pool->champion3.done : %d\n",dead_pool->champion3.done);
	ft_fprintf(2,	 "dead_pool->champion4.done : %d\n",dead_pool->champion4.done);
}

void						ft_vm_instr(unsigned char arena[],
										t_dead_pool *dead_pool,
										unsigned const int nb_champion,
										unsigned const int current_cycle)
{
	(void)nb_champion;
	int			i;

	i = 0;

	ft_printf("nb_champion : %d\n", nb_champion);
	dead_pool->i_champ = &dead_pool->champion1;
	while (i < MAX_PLAYERS)
	{
		if (dead_pool->i_champ->pc)
		{
			if (dead_pool->i_champ->next_cycle <= current_cycle)
				ft_vm_instr_champion_routine(arena, dead_pool, current_cycle);
			else
				dead_pool->i_champ->done = 1;
		}
		++dead_pool->i_champ;
		++i;
		if (i == MAX_PLAYERS)
		{
			ft_printf("{red:out condition}\n");
			ft_printf("CHAMP_DONE : %d\n", CHAMP_DONE);
			ft_printf("champ1 :%d\n", dead_pool->champion1.done);
			ft_printf("champ2 :%d\n", dead_pool->champion2.done);
			ft_printf("champ3 :%d\n", dead_pool->champion3.done);
			ft_printf("champ4 :%d\n", dead_pool->champion4.done);
			if (CHAMP_DONE == nb_champion)
			{
				break ;
			}
			else
			{
				i ^= i;
				dead_pool->i_champ = &dead_pool->champion1;
			}
			getchar();
		}
		#if 0
		if ((dead_pool->i_champ->next_cycle <= current_cycle)
					&& dead_pool->i_champ->pc)
			ft_vm_instr_champion_routine(arena, dead_pool, current_cycle);
		else if (dead_pool->i_champ->pc)
			dead_pool->i_champ->done = 1;
		if (i == (MAX_PLAYERS - 1))
		{
			ft_printf("{red:out condition}\n");
			if (CHAMP_DONE == nb_champion)
			{
				ft_printf("CHAMP_DONE : %d\n", CHAMP_DONE);
				ft_printf("champ1 :%d\n", dead_pool->champion1.done);
				ft_printf("champ2 :%d\n", dead_pool->champion2.done);
				ft_printf("champ3 :%d\n", dead_pool->champion3.done);
				ft_printf("champ4 :%d\n", dead_pool->champion4.done);
				break ;
			}
			else
				i ^= i;
		}
		#endif
	}
	ft_printf("{red: instr routine should stop}\n");
	getchar();


	#if 0
	dead_pool->i_champ = &dead_pool->champion1;
	ft_vm_instr_champion_routine(arena, dead_pool, current_cycle);
	++dead_pool->i_champ;
	ft_vm_instr_champion_routine(arena, dead_pool, current_cycle);
	ft_printf("champ {green:CHAMP_DONE} : %d\n", CHAMP_DONE);
	dead_pool->i_champ = &dead_pool->champion1;
	ft_vm_instr_champion_routine(arena, dead_pool, current_cycle);
	++dead_pool->i_champ;
	ft_vm_instr_champion_routine(arena, dead_pool, current_cycle);
	#endif
	#if 0
	int					i;

	if (TEST_MODE)
	{
		int i = 0;
		{
			DEBUG_MODE ? ft_printf("{yellow:read in}\n") : 0;
			//ft_vm_instr_decode(&dead_pool->champion1);
			//ft_vm_instr_exec(arena, dead_pool, &dead_pool->champion1);
			DEBUG_MODE ? ft_printf("{yellow:read out}\n") : 0;
			++i;
		}
		getchar();
		return ;
	}

	while (1)
	{
		i = 0;
		dead_pool->i_champ = &dead_pool->champion1;
		while (i < 4)
		{
			ft_vm_instr_champion_routine(arena, dead_pool, current_cycle);
			ft_printf("loop CHAMP_DONE : %d\n", CHAMP_DONE);
			if (CHAMP_DONE == nb_champion)
			{
				ft_printf("supposed to break here\n");
				getchar();
				break;
			}
			++i;
			++dead_pool->i_champ;
			ft_printf("end of LOOP\n");
			getchar();
		}
		DEBUG_MODE ? ft_printf("CHAMP_DONE : %d, nb_champion : %d\n", CHAMP_DONE, nb_champion) : 0;
		if (CHAMP_DONE == nb_champion)
		{
			ft_vm_instr_init_done(dead_pool);
		}
		DEBUG_MODE ? getchar() : 0;
	}
	DEBUG_MODE ? ft_printf("CHAMP_DONE : %d and nb_champion : %d\n", CHAMP_DONE, nb_champion) : 0;
	#endif
}
