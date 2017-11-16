/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_end_of_game.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:01:38 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/16 08:17:54 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
//TODO : presentation

#ifndef CHAMP_DONE
# define CHAMP_DONE (dead_pool->champ[0].done + dead_pool->champ[1].done + dead_pool->champ[2].done + dead_pool->champ[3].done)
#endif

int					ft_vm_instr_end_of_game(t_dead_pool *dead_pool, int *nb_champion)
{
	int			left;

	DEBUG_MODE ? ft_printf("{bblack:ft_vm_instr_end_of_game} {green:in}\n") : 0;
	ft_printf("CHAMP_DONE : %d nb_champion : %d %s->live : %d\n", CHAMP_DONE, *nb_champion, dead_pool->champ[CHAMP_IDX].header.prog_name, dead_pool->champ[CHAMP_IDX].live);
	left = CHAMP_DONE;
	if ((!dead_pool->champ[CHAMP_IDX].live) && (left != (*nb_champion - 1)))
	{
		if (!ft_list_is_empty(&dead_pool->champ[CHAMP_IDX].process_head))
			ft_vm_instr_close_process(dead_pool);
		--*nb_champion;
		ft_memset((void *)&dead_pool->champ[CHAMP_IDX], 0, sizeof(t_champion));
		return (EXIT_FAILURE);
	}
	if ((left == (*nb_champion - 1)) && (!dead_pool->champ[CHAMP_IDX].live))
	{
		{
			if (!ft_list_is_empty(&dead_pool->champ[CHAMP_IDX].process_head))
				ft_vm_instr_close_process(dead_pool);
			ft_memset((void *)&dead_pool->champ[CHAMP_IDX], 0, sizeof(t_champion));
			ft_printf("{bblack:ft_vm_instr_end_of_game} {green:out}\n");
			return (EXIT_SUCCESS);
		}

	}
	ft_printf("{bblack:ft_vm_instr_end_of_game} {red:out}\n");
	return (EXIT_FAILURE);
}

		#if 0
		if  ((left == (*nb_champion - 1)))
		{
			dead_pool->idx ^= dead_pool->idx;
			while (CHAMP_IDX < MAX_PLAYERS)
			{
				if (!ft_list_is_empty(&dead_pool->champ[CHAMP_IDX].process_head))
					ft_vm_instr_close_process(dead_pool);
				ft_memset((void *)&dead_pool->champ[CHAMP_IDX], 0, sizeof(t_champion));
				--*nb_champion;
			}
		}
		#endif
	#if 0
	if ((left == (*nb_champion - 1)) && (!dead_pool->champ[CHAMP_IDX].live))
	{
		dead_pool->idx ^= dead_pool->idx;
		while (CHAMP_IDX < MAX_PLAYERS)
		{
			ft_printf("while loop (%d champ  left):\n%s ---> %d live(s)\n", left, dead_pool->champ[CHAMP_IDX].header.prog_name, dead_pool->champ[CHAMP_IDX].live);
			if (dead_pool->champ[CHAMP_IDX].pc && !dead_pool->champ[CHAMP_IDX].live && left)
			{
				if (!ft_list_is_empty(&dead_pool->champ[CHAMP_IDX].process_head))
					ft_vm_instr_close_process(dead_pool);
				ft_memset((void *)&dead_pool->champ[CHAMP_IDX], 0, sizeof(t_champion));
				--left;
			}
			++dead_pool->idx;
		}
		return (EXIT_SUCCESS);
	}
	#endif
	// Necessary ?
	//CHAMP_IDX ^= CHAMP_IDX;
