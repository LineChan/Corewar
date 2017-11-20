/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_lld.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:33:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/20 14:46:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

// TODO: presentation
/*
* brief      		Log function for the lld instruction
*
*/

void 				ft_vm_log_lld(t_dead_pool *dead_pool,
								unsigned char *ptr,
								unsigned int address)
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "lld");
	ft_vm_log_arg(dead_pool);
	ft_log("\t\treg[%d] = %d --> arena[%d]\n", *ptr, dead_pool->i_champ->reg[*ptr], address);
}
