/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_process_routine.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:53:02 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/22 18:24:59 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

/*
* brief      			Execute a routine for each process
*
* param arena			Memory dedicated to the Virtual Machine
* param dead_pool		t_dead_pool struct for the game
* param nb_champion		Number of alive champions in the arena
*/

void 			ft_vm_arena_process_routine(unsigned char arena[2][MEM_SIZE],
											t_dead_pool *dead_pool,
											t_champion *i_champ)
{
	(void)arena;
	(void)dead_pool;
	// if the instruction works
	ft_vm_arena_instr_routine(arena, dead_pool, i_champ);
	if ((i_champ->pc - &arena[0][0] - i_champ->index) >= CHAMP_MAX_SIZE)
		i_champ->pc = &arena[0][i_champ->index];
	//Notif process_
}
