/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_upload_champion.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 22:40:26 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/22 14:13:31 by mvillemi         ###   ########.fr       */
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

void			ft_vm_arena_upload_champion(unsigned char arena[2][MEM_SIZE],
											t_dead_pool *dead_pool,
											unsigned int *nb_champion)
{
	int		index;
	int		step;

	/* Find the distance between 2 champions */
	step = MEM_SIZE / *nb_champion;
	dead_pool->idx = 0;
	index = 0;
	dead_pool->idx ^= dead_pool->idx;
	/* Read headers for each champion*/
	while (dead_pool->idx < MAX_PLAYERS)
	{
		if (dead_pool->option.fd[dead_pool->idx])
		{
			/* Set up the starting position in the arena */
			dead_pool->champ[dead_pool->idx].index = index;
			/* Set up the Program Counter at the starting position */
			dead_pool->champ[dead_pool->idx].pc = &arena[0][index];
			index += step;
			/* Put the champion's number in the 1st register */
			dead_pool->champ[dead_pool->idx].reg[1] = dead_pool->idx + 1;
			/* Initialize the subprocess' list */
			INIT_LIST_HEAD(dead_pool->champ[dead_pool->idx].process_head);
			/* Close the corresponding File Descriptor */
			close(dead_pool->option.fd[dead_pool->idx]);
		}
		++dead_pool->idx;
	}
}
