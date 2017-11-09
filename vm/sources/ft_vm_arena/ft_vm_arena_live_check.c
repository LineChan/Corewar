/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_live_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:04:13 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/08 18:19:47 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void		ft_vm_arena_live_check(t_dead_pool *dead_pool, int *nb_champion)
{
	if (dead_pool->champion1.pc)
	{
		if (!dead_pool->champion1.live)
		{
			dead_pool->champion1.pc = 0;
			--*nb_champion;
		}
		else
			ft_printf("Player 1 ({green:%s}) is alive\n", dead_pool->champion1.header.prog_name);
	}
	if (dead_pool->champion2.pc)
	{
		if (!dead_pool->champion2.live)
		{
			dead_pool->champion2.pc = 0;
			--*nb_champion;
		}
		else
			ft_printf("Player 2 ({green:%s}) is alive\n", dead_pool->champion2.header.prog_name);
	}
	if (dead_pool->champion3.pc)
	{
		if (!dead_pool->champion3.live)
		{
			dead_pool->champion3.pc = 0;
			--*nb_champion;
		}
		else
			ft_printf("Player 3 ({green:%s}) is alive\n", dead_pool->champion3.header.prog_name);
	}
	if (dead_pool->champion4.pc)
	{
		if (!dead_pool->champion4.live)
		{
			dead_pool->champion4.pc = 0;
			--*nb_champion;
		}
		else
			ft_printf("Player 4 ({green:%s}) is alive\n", dead_pool->champion4.header.prog_name);
	}
}
