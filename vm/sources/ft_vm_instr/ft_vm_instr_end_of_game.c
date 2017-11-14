/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_end_of_game.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:01:38 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/14 23:31:05 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
//TODO : presentation

#ifndef CHAMP_DONE
# define CHAMP_DONE (dead_pool->champ[0].done + dead_pool->champ[1].done + dead_pool->champ[2].done + dead_pool->champ[3].done)
#endif

int					ft_vm_instr_end_of_game(t_dead_pool *dead_pool, int *nb_champion)
{
	ft_printf("CHAMP_DONE : %d nb_champion : %d i_champ->live : %d\n", CHAMP_DONE, *nb_champion, dead_pool->champ[dead_pool->idx].live);
	int			left;

	left = CHAMP_DONE;
	if ((left == (*nb_champion - 1)) && (!dead_pool->champ[dead_pool->idx].live))
	{
		dead_pool->idx ^= dead_pool->idx;
		while (dead_pool->idx < MAX_PLAYERS)
		{
			if (dead_pool->champ[dead_pool->idx].pc && !dead_pool->champ[dead_pool->idx].live && left)
			{
				// TODO : free all nodes from fork and lfork
				ft_memset((void *)&dead_pool->champ[dead_pool->idx], 0, sizeof(t_champion));
				--left;
			}
			++dead_pool->idx;
		}
		return (EXIT_SUCCESS);
	}
	// Necessary ?
	//dead_pool->idx ^= dead_pool->idx;
	return (EXIT_FAILURE);
}
