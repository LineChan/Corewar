/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_lldi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:44:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/20 15:41:23 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_vm.h"
#include "ft_log.h"

// TODO: presentation
/*
* brief      		Log function for the lldi instruction
*
*/

void 				ft_vm_log_lldi(t_dead_pool *dead_pool,
								unsigned char *ptr,
								unsigned int address)
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "lldi");
	ft_vm_log_arg(dead_pool);
	ft_log("\t\treg[%d] = %d --> arena[%d]\n", *ptr, dead_pool->i_champ->reg[*ptr], address);
}
