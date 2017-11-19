/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_live.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 18:20:09 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/19 00:03:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"


// TODO: presentation
/*
* brief      		Log function for the live instruction
*                   Take one parameter
*
* param dead_pool
* param number          Number of the champion had the live instruction
*/

void 				ft_vm_log_live(t_dead_pool *dead_pool, int nb)
{
    if ((CHAMP_IDX + 1) == nb)
        ft_log("  Cycle %-7d Player %d [✓] %-5s : Player %d\n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "live", nb);
    else
        ft_log("  Cycle %-7d Player %d [✗] %-5s : Player %d\n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "live", nb);
}
