/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_upload_champion.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 22:40:26 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/20 19:34:38 by mvillemi         ###   ########.fr       */
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
void				ft_vm_arena_upload_champion(unsigned char arena[],
												t_dead_pool *dead_pool,
												unsigned int *nb_champion)
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
		#if 0
		if (option[dead_pool->idx + 1])
		{
			/* Read from the header and store it in a structure */
			read(option[dead_pool->idx + 1], &arena[index], dead_pool->champ[dead_pool->idx].header.prog_size);
			/* Set up the starting position in the arena */
			dead_pool->champ[dead_pool->idx].index = index;
			/* Set up the Program Counter at the starting position */
			dead_pool->champ[dead_pool->idx].pc = &arena[index];
			index += step;
			/* Put the champion's number in the first register */
			dead_pool->champ[dead_pool->idx].reg[1] = dead_pool->idx + 1;
			/* Set up the carry */
			dead_pool->champ[dead_pool->idx].carry = 1;
			/* Initialize the subprocess list */
			INIT_LIST_HEAD(dead_pool->champ[dead_pool->idx].process_head);
			/* Close the File Descriptor */
			close(option[dead_pool->idx + 1]);
		}
		#endif
		++dead_pool->idx;
	}
}
