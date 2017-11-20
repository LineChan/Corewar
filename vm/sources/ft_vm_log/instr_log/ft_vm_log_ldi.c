/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_ldi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:37:34 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/20 15:23:45 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

//TODO : Presentation
void               ft_vm_log_ldi(t_dead_pool *dead_pool,
								unsigned char *ptr,
								unsigned int address)
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n",
						dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "ldi");
	ft_vm_log_arg(dead_pool);
	ft_log("\t\treg[%d] =  %d --> arena[(PC + (%d %% IDX_MOD)) %% MEM_SIZE]\n",
						*ptr, dead_pool->i_champ->reg[*ptr], address);
}
