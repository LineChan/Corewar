/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:08:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/09 20:47:07 by mvillemi         ###   ########.fr       */
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
	if (dead_pool->i_champ->pc)
	{
		if (DEBUG_MODE)
		{
			ft_printf("next_cycle : %d current : %d\n", dead_pool->i_champ->next_cycle, current_cycle);
			ft_printf("Champion's name : {yellow:%s}\n", dead_pool->i_champ->header.prog_name);
		}
		if (dead_pool->i_champ->next_cycle <= current_cycle)
		{
			if (ft_vm_instr_decode(dead_pool->i_champ) == EXIT_SUCCESS)
				ft_vm_instr_exec(arena, dead_pool);
			else
				dead_pool->i_champ->pc += 1;
			ft_printf("current : %d, prog_size : %d\n", dead_pool->i_champ->pc - arena - dead_pool->i_champ->index,  dead_pool->i_champ->header.prog_size);
			if ((dead_pool->i_champ->pc - arena - dead_pool->i_champ->index) == dead_pool->i_champ->header.prog_size)
				dead_pool->i_champ->pc -= dead_pool->i_champ->header.prog_size;
			getchar();
		}
		else
			++*instr_left;
	}
	else
		DEBUG_MODE ? ft_printf("{red:no champion}\n") : 0;
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

	while (instr_left != nb_champion)
	{
		i = 0;
		dead_pool->i_champ = &dead_pool->champion1;
		while (i < 4)
		{
			ft_vm_instr_champion_routine(arena, dead_pool, current_cycle, &instr_left);
			++i;
			++dead_pool->i_champ;
			getchar();
		}
		getchar();
	}
	ft_printf("instr_left : %d and nb_champion : %d\n", instr_left, nb_champion);
}
