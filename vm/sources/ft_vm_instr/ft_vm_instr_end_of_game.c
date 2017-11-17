/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_end_of_game.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:01:38 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/17 14:16:55 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
//TODO : presentation

#ifndef CHAMP_DONE
# define CHAMP_DONE (dead_pool->champ[0].done + dead_pool->champ[1].done + dead_pool->champ[2].done + dead_pool->champ[3].done)
#endif

int					ft_vm_instr_end_of_game(t_dead_pool *dead_pool,
											unsigned int *nb_champion)
{
	unsigned int			left;

	DEBUG_MODE ? ft_printf("{bblack:ft_vm_instr_end_of_game} {green:in}\n") : 0;
	ft_printf("CHAMP_DONE : %d nb_champion : %d %s->live : %d\n", CHAMP_DONE, *nb_champion, dead_pool->champ[CHAMP_IDX].header.prog_name, dead_pool->champ[CHAMP_IDX].live);
	left = CHAMP_DONE;
	/* If the current champion hasn't done until the last cycle to die */
	/* and there is only one champion left in the arena, the game ends */
	if (!dead_pool->champ[CHAMP_IDX].live)
	{
		/* Close all the process created by fork and lfork if necessary */
		if (!ft_list_is_empty(&dead_pool->champ[CHAMP_IDX].process_head))
			ft_vm_instr_close_process(dead_pool);
		ft_memset((void *)&dead_pool->champ[CHAMP_IDX], 0, sizeof(t_champion));
		--*nb_champion;
		return ((left == (*nb_champion - 1)) ? EXIT_SUCCESS : EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}
