/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_lfork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:42:12 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/20 15:54:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

//TODO : Presentation
void			ft_vm_log_lfork(t_dead_pool *dead_pool, unsigned int jump)
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "lfork");
	ft_vm_log_arg(dead_pool);
	ft_log("\t\tlfork at ((PC + %d) %% MEM_SIZE)\n", jump);
}
