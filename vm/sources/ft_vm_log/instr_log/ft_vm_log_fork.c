/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:21:58 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/20 15:50:15 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

//TODO : Presentation
void			ft_vm_log_fork(t_dead_pool *dead_pool, unsigned int jump)
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "fork");
	ft_vm_log_arg(dead_pool);
	ft_log("\t\tfork at ((PC + (%d %% IDX_MOD) %% MEM_SIZE)\n", jump);
}
