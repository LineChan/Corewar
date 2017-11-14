/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_end_of_game.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:01:38 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/14 10:55:18 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
//TODO : presentation

#ifndef CHAMP_DONE
# define CHAMP_DONE (dead_pool->champion1.done + dead_pool->champion2.done + dead_pool->champion3.done + dead_pool->champion4.done)
#endif

int					ft_vm_instr_end_of_game(t_dead_pool *dead_pool, int *nb_champion)
{
	ft_printf("CHAMP_DONE : %d nb_champion : %d i_champ->live : %d\n", CHAMP_DONE, *nb_champion, dead_pool->i_champ->live);
	int			left;
	int			i;

	left = CHAMP_DONE;
	i = 0;
	if ((left == (*nb_champion - 1)) && (!dead_pool->i_champ->live))
	{
		dead_pool->i_champ = &dead_pool->champion1;
		while (i < MAX_PLAYERS)
		{
			if (dead_pool->i_champ->pc && !dead_pool->i_champ->live && left)
			{
				ft_memset((void *)&(*dead_pool->i_champ), 0, sizeof(t_champion));
				--left;
			}
			++dead_pool->i_champ;
			++i;
		}
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
