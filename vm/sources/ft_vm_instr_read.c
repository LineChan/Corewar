/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_read.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:08:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/01 18:55:13 by mvillemi         ###   ########.fr       */
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
* param nb_champion	Champions number
*/

extern uint8_t	g_direct_jump_table_from_instr[17];

int				ft_vm_instr_read(unsigned char arena[],
								t_dead_pool *dead_pool,
								const int nb_champion)
{
	unsigned int		instr_left;;
	unsigned int		current_cycle;

	if (DEBUG_MODE)
	{
		ft_printf("nb_champion : %d\n", nb_champion);
		ft_printf("Read instruction :\n");
	}
	current_cycle = 0;
	instr_left = 0;
	if (dead_pool->champion1.pc)
	{
		DEBUG_MODE ? ft_printf("Champion1 : %s\n", dead_pool->champion1.header.prog_name) : 0;
		if  (dead_pool->champion1.next_cycle <= current_cycle)
		{
			ft_vm_instr_decode(&dead_pool->champion1);
			ft_vm_instr_exec(arena, &dead_pool->champion1);

		}
		else
			++instr_left;
	}
	if (dead_pool->champion2.pc)
	{
		DEBUG_MODE ? ft_printf("\nChampion2 : %s\n", dead_pool->champion2.header.prog_name) : 0;
		if(dead_pool->champion2.next_cycle <= current_cycle)
		{
			ft_vm_instr_decode(&dead_pool->champion2);
			ft_vm_instr_exec(arena, &dead_pool->champion2);
		}
		else
			++instr_left;
	}
	if (dead_pool->champion3.pc)
	{
		DEBUG_MODE ? ft_printf("\nChampion3 : %s\n", dead_pool->champion3.header.prog_name) : 0;
		if (dead_pool->champion3.next_cycle <= current_cycle)
		{
			ft_vm_instr_decode(&dead_pool->champion3);
			ft_vm_instr_exec(arena, &dead_pool->champion3);
		}
		else
			++instr_left;
	}
	if (dead_pool->champion4.pc)
	{
		DEBUG_MODE ? ft_printf("\nChampion4 : %s\n", dead_pool->champion4.header.prog_name) : 0;
		if(dead_pool->champion4.next_cycle <= current_cycle)
		{
			ft_vm_instr_decode(&dead_pool->champion4);
			ft_vm_instr_exec(arena, &dead_pool->champion4);
		}
		else
			++instr_left;
	}
	DEBUG_MODE ? write(1, "\n", 1) : 0;
	return (instr_left ? EXIT_FAILURE : EXIT_SUCCESS);
}
