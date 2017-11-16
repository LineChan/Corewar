/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_live_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:04:13 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/16 08:17:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void		ft_vm_arena_live_check(t_dead_pool *dead_pool, int *nb_champion)
{
	t_list		*it;

	(void)nb_champion;
	DEBUG_MODE ? ft_printf("{bblack:ft_vm_arena_live_check} {green:in}\n") : 0;
	dead_pool->idx ^= dead_pool->idx;
	while (dead_pool->idx < MAX_PLAYERS)
	{
		if (dead_pool->champ[dead_pool->idx].pc)
		{
			if (!ft_list_is_empty(&dead_pool->champ[dead_pool->idx].process_head))
			{
				it = dead_pool->champ[dead_pool->idx].process_head.next;
				while (it != &dead_pool->champ[dead_pool->idx].process_head)
				{
					if (C_PROCESS(it)->process.live)
					{
						dead_pool->champ[dead_pool->idx].live += C_PROCESS(it)->process.live;
						C_PROCESS(it)->process.live ^= C_PROCESS(it)->process.live;
					}
					it = it->next;
				}
			}
			if (dead_pool->champ[dead_pool->idx].live)
			{
				dead_pool->champ[dead_pool->idx].live ^= dead_pool->champ[dead_pool->idx].live;
			}
			else
			{
				--*nb_champion;
				if (!ft_list_is_empty(&dead_pool->champ[dead_pool->idx].process_head))
					ft_vm_instr_close_process(dead_pool);
				ft_memset((void *)&dead_pool->champ[dead_pool->idx], 0, sizeof(t_champion));
			}
		}
		++dead_pool->idx;
	}

	DEBUG_MODE ? ft_printf("{bblack:ft_vm_arena_live_check} {green:out}\n") : 0;
	#if 0
	dead_pool->idx ^= dead_pool->idx;
	while (dead_pool->idx < MAX_PLAYERS)
	{
		ft_printf("live check : %s [ %d live(s)]\n", dead_pool->champ[dead_pool->idx].header.prog_name, dead_pool->champ[dead_pool->idx].live);
		if (dead_pool->champ[dead_pool->idx].pc)
		{
			if (!dead_pool->champ[dead_pool->idx].live)
			{
				dead_pool->champ[dead_pool->idx].pc = 0;
				--*nb_champion;
			}
			else
				ft_printf("Player %d ({green:%s}) is alive\n", CHAMP_IDX + 1, dead_pool->champ[CHAMP_IDX].header.prog_name);
		}
		++dead_pool->idx;
	}
	#endif
	#if 0
	int		i;

	i = 0;
	// TODO: check lives given by fork
	dead_pool->i_champ = &dead_pool->champion1;
	while (i < 4)
	{
		ft_printf("live check : %s [ %d live(s)]\n", dead_pool->i_champ->header.prog_name, dead_pool->i_champ->live);
		if (dead_pool->i_champ->pc)
		{
			if (!dead_pool->i_champ->live)
			{
				dead_pool->i_champ->pc = 0;
				--*nb_champion;
			}
			else
				ft_printf("Player %d ({green:%s}) is alive\n", i + 1, dead_pool->i_champ->header.prog_name);
		}
		++dead_pool->i_champ;
		++i;
	}
	#endif
}
