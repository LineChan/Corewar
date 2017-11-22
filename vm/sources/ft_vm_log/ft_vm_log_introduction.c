/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_introduction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:37:15 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/22 14:09:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void			ft_vm_log_introduction(t_dead_pool *dead_pool)
{
	ft_log("# ----------------  NEW EPIC BATTLE ----------------\n");
	/* Write the name of the all the champions */
	dead_pool->idx ^= dead_pool->idx;
	while (dead_pool->idx < MAX_PLAYERS)
	{
		if (dead_pool->option.fd[dead_pool->idx])
			ft_log("# Player %d: %s\n", dead_pool->idx + 1,
					dead_pool->champ[dead_pool->idx   ].header.prog_name);
		++dead_pool->idx;
	}
	//ft_log("# Starting cycle : %d\n", OPTION_WAIT);
	ft_log("# --------------------------------------------------\n");
}
