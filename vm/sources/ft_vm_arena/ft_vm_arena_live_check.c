/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_live_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:04:13 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/11 15:30:18 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void		ft_vm_arena_live_check(t_dead_pool *dead_pool, int *nb_champion)
{
	int		i;

	i = 0;
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
}
