/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:08:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/09 19:14:31 by mvillemi         ###   ########.fr       */
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
#include <libc.h>

void				ft_vm_instr_champion_routine(unsigned char arena[],
												t_dead_pool * dead_pool,
												unsigned const int current_cycle,
												unsigned int *instr_left)
{

	DEBUG_MODE ? ft_printf("{bblack:ft_vm_instr_champion_routine} {green:in}\n") : 0;
	(void)arena;
	(void)current_cycle;
	if (dead_pool->i_champ->pc)
	{
		if (DEBUG_MODE)
		{
			ft_printf("next_cycle : %d current : %d\n", dead_pool->i_champ->next_cycle, current_cycle);
			ft_printf("Champion's name : %s\n", dead_pool->i_champ->header.prog_name);
		}
		if  (dead_pool->i_champ->next_cycle <= current_cycle)
		{
			if (ft_vm_instr_decode(dead_pool->i_champ) == EXIT_SUCCESS)
				ft_vm_instr_exec(arena, dead_pool);
			else
				dead_pool->i_champ->pc += 1;
		}
		else
			++*instr_left;
	}
	#if 0
	instr_left = 0;
	if (dead_pool->champion1.pc)
	{
		//ft_vm_instr_routine(arena, dead_pool, &dead_pool->champion1, current_cycle);
		DEBUG_MODE ? ft_printf("Champion1 : %s\n", dead_pool->champion1.header.prog_name) : 0;
		if  (dead_pool->champion1.next_cycle <= current_cycle)
		{
			#if 1
			if (ft_vm_instr_decode(&dead_pool->champion1) == EXIT_SUCCESS)
				ft_vm_instr_exec(arena, dead_pool, &dead_pool->champion1);
			else
				dead_pool->champion1.pc += 1;
				#endif
		}
		else
			++instr_left;
	}
	#endif
	ft_printf("{bblack:ft_vm_instr_champion_routine} {green:out}\n");
}

void				ft_vm_instr(unsigned char arena[],
								t_dead_pool *dead_pool,
								unsigned const int nb_champion,
								unsigned const int current_cycle)
{
	unsigned int		instr_left;
	int					i;

	instr_left = 0;
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

	i = 0;
	dead_pool->i_champ = &dead_pool->champion1;
	while (instr_left != nb_champion)
	{
		while (i < 4)
		{
			ft_vm_instr_champion_routine(arena, dead_pool, current_cycle, &instr_left);
			++i;
			++dead_pool->i_champ;
			getchar();
		}
		ft_printf("{bblack:ft_vm_instr_read} {green:out}\n");
		getchar();
		#if 0
		if (dead_pool->champion2.pc)
		{
			DEBUG_MODE ? ft_printf("\nChampion2 : %s\n", dead_pool->champion2.header.prog_name) : 0;
			if(dead_pool->champion2.next_cycle <= current_cycle)
			{
				if (ft_vm_instr_decode(&dead_pool->champion2) == EXIT_SUCCESS)
					ft_vm_instr_exec(arena, dead_pool, &dead_pool->champion2);
				else
					dead_pool->champion2.pc += 1;
			}
			else
			++instr_left;
		}
		if (dead_pool->champion3.pc)
		{
			DEBUG_MODE ? ft_printf("\nChampion3 : %s\n", dead_pool->champion3.header.prog_name) : 0;
			if (dead_pool->champion3.next_cycle <= current_cycle)
			,
								unsigned const int current_cycle	{
				if (ft_vm_instr_decode(&dead_pool->champion3) == EXIT_SUCCESS)
					ft_vm_instr_exec(arena, dead_pool, &dead_pool->champion3);
				else
					dead_pool->champion3.pc += 1;
			}
			else
			++instr_left;
		}
		if (dead_pool->champion4.pc)
		{
			DEBUG_MODE ? ft_printf("\nChampion4 : %s\n", dead_pool->champion4.header.prog_name) : 0;
			if(dead_pool->champion4.next_cycle <= current_cycle)
			{
				if (ft_vm_instr_decode(&dead_pool->champion4) == EXIT_SUCCESS)
					ft_vm_instr_exec(arena, dead_pool, &dead_pool->champion4);
				else
					dead_pool->champion4.pc += 1;
			}
			else
			++instr_left;
		}
		DEBUG_MODE ? write(1, "\n", 1) : 0;
		DEBUG_MODE ? ft_printf("{bblack:ft_vm_instr_read} {green:out}\n") : 0;
		ft_printf("instr_left : %d\n", instr_left);
		#endif
		}
	ft_printf("instr_left : %d and nb_champion : %d\n", instr_left, nb_champion);
	return ;
	//return ((instr_left == nb_champion) ? EXIT_SUCCESS : EXIT_FAILURE);
}
