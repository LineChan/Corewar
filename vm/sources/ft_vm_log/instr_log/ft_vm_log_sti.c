/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_sti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:10:31 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/19 18:20:39 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

//TODO : Presentation
void               ft_vm_log_sti(t_dead_pool *dead_pool,
									unsigned char arena[],
									unsigned int reg,
									unsigned int address)
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "sti");
	ft_vm_log_arg(dead_pool);
	ft_log("\t\tarena[%d] = %d --> reg[%d]\n", address,
												arena[MOD(address)], reg);
}
