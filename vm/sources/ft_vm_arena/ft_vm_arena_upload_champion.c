/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_upload_champion.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 22:40:26 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/14 23:59:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/*
* brief      		Upload champions in the arena
*
* param fd			File Descriptor
* param arena		Memory dedicated to the virtual machine
* param dead_pool	Structure gathering all the champions
* param nb_champion	Champions' number
*/

//TODO: libc

#include <libc.h>
#if 0
static void 		ft_vm_arena_up_routine(const int fd,
												unsigned char arena[],
												t_champion *champ,
												int index)
{
	read(fd, &arena[index], champ->header.prog_size);
	champ->index = index;
	INIT_LIST_HEAD(champ->process_head);
	close(fd);
}
#endif

void				ft_vm_arena_upload_champion(unsigned char arena[],
												int option[],
												t_dead_pool *dead_pool,
												int *nb_champion)
{
	int		index;
	int		step;

	ft_memset((void *)arena, 0, MEM_SIZE);
	!*nb_champion ? EXIT_FAIL("Error : no champion") : 0;
	/* Find the distance between 2 champions */
	step = MEM_SIZE / *nb_champion;
	dead_pool->idx = 0;
	index = 0;
	// Reset just in case, check if it can be removed
	dead_pool->idx ^= dead_pool->idx;
	/* Read headers for each champion*/
	while (dead_pool->idx < MAX_PLAYERS)
	{
		if (option[dead_pool->idx + 1])
		{
			/* Read from the header and store it in a structure */
			read(option[dead_pool->idx + 1], &arena[index], dead_pool->champ[dead_pool->idx].header.prog_size);
			/* Set up the starting position in the arena */
			dead_pool->champ[dead_pool->idx].index = index;
			/* Set up the Program Counter at the starting position */
			dead_pool->champ[dead_pool->idx].pc = &arena[index];
			/* Put the champion's number in the first register */
			dead_pool->champ[dead_pool->idx].reg[0] = dead_pool->idx + 1;
			/* Initialize the subprocess list */
			INIT_LIST_HEAD(dead_pool->champ[dead_pool->idx].process_head);
			close(option[dead_pool->idx + 1]);
			index += step;
		}
		++dead_pool->idx;
	}
	#if 0
	if (option[1])
	{
		ft_vm_arena_up_routine(option[1], arena, &dead_pool->champion1, index);
		dead_pool->champion1.pc = &arena[index];
		dead_pool->champion1.reg[0] = 1;

		index += step;

	}
	if (option[2])
	{
		ft_vm_arena_up_routine(option[2], arena, &dead_pool->champion2, index);
		dead_pool->champion2.pc = &arena[index];
		dead_pool->champion2.reg[0] = 2;
		index += step;
	}
	if (option[3])
	{
		ft_vm_arena_up_routine(option[3], arena, &dead_pool->champion3, index);
		dead_pool->champion3.pc = &arena[index];
		dead_pool->champion3.reg[0] = 3;
		index += step;
	}
	if (option[4])
	{
		ft_vm_arena_up_routine(option[4], arena, &dead_pool->champion4, index);
		dead_pool->champion4.pc = &arena[index];
		dead_pool->champion4.reg[0] = 4;
	}
	#endif
}
