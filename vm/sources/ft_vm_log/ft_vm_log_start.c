/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:37:15 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/21 11:50:04 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void			ft_vm_log_start(t_dead_pool *dead_pool)
{
	int			i;

	i = 0;
	ft_log("# ----------------  NEW EPIC BATTLE ----------------\n");
	/* Write the name of the all the champions */
	while (i < MAX_PLAYERS)
	{
		if (dead_pool->champ[CHAMP_IDX].pc)
			ft_log("# Player %d: %s\n", CHAMP_IDX + 1, dead_pool->champ[CHAMP_IDX].header.prog_name);
		++i;
		++dead_pool->idx;
	}
	//ft_log("# Starting cycle : %d\n", OPTION_WAIT);
	ft_log("# --------------------------------------------------\n");
}
