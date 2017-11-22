/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_live_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:04:13 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/20 19:38:52 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void		ft_vm_arena_live_check(t_dead_pool *dead_pool,
									unsigned int *nb_champion)
{
	(void)dead_pool;
	(void)nb_champion;
	#if 0
	t_list		*it;

	(void)nb_champion;
	DEBUG_MODE ? ft_printf("{bblack:ft_vm_arena_live_check} {green:in}\n") : 0;
	dead_pool->idx ^= dead_pool->idx;
	while (dead_pool->idx < MAX_PLAYERS)
	{
		/* If the champion exists */
		if (dead_pool->champ[dead_pool->idx].pc)
		{
			/* Check if there is a subprocess */
			if (!ft_list_is_empty(&dead_pool->champ[dead_pool->idx].process_head))
			{
				/* Go through the subprocess' list */
				/* and check if the live instruction was executed */
				it = dead_pool->champ[dead_pool->idx].process_head.next;
				while (it != &dead_pool->champ[dead_pool->idx].process_head)
				{
					if (C_PROCESS(it)->process.live)
					{
						/* Add the subprocess lives to the main champion */
						dead_pool->champ[dead_pool->idx].live += C_PROCESS(it)->process.live;
						/* Reset the number of lives */
						C_PROCESS(it)->process.live ^= C_PROCESS(it)->process.live;
					}
					it = it->next;
				}
			}
			if (dead_pool->champ[dead_pool->idx].live)
			{
				ft_printf("Player %d {yellow:%s} is alive !", dead_pool->idx + 1, dead_pool->champ[dead_pool->idx].header.prog_name);
				/* Reset the main champion's lives */
				dead_pool->champ[dead_pool->idx].live ^= dead_pool->champ[dead_pool->idx].live;
			}
			else
			{
				/* If the instruction life wasn't executed, */
				/* the champion and its eventual subprocess are deleted */
				--*nb_champion;
				if (!ft_list_is_empty(&dead_pool->champ[dead_pool->idx].process_head))
					ft_vm_instr_close_process(dead_pool);
				ft_memset((void *)&dead_pool->champ[dead_pool->idx], 0, sizeof(t_champion));
			}
		}
		++dead_pool->idx;
	}
	#endif
}
