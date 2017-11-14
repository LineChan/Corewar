/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_live_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:04:13 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/14 21:29:22 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void		ft_vm_arena_live_check(t_dead_pool *dead_pool, int *nb_champion)
{
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
				ft_printf("Player %d ({green:%s}) is alive\n", dead_pool->idx + 1, dead_pool->champ[dead_pool->idx].header.prog_name);
		}
		++dead_pool->idx;
	}
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
