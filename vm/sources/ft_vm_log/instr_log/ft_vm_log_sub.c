/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 23:55:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/19 16:44:47 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

//TODO : presentation
void 			ft_vm_log_sub(t_dead_pool *dead_pool, unsigned int sub[])
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n",
			dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "sub");
	ft_vm_log_arg(dead_pool);
	ft_log("\t\treg[%d] = %d --> [%d] - [%d]\n", sub[2],
				dead_pool->i_champ->reg[sub[2]], sub[0], sub[1]);
}
