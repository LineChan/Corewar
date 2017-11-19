/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 23:55:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/19 00:08:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

//TODO : presentation
void 			ft_vm_log_sub(t_dead_pool *dead_pool, unsigned int sub[])
{
	ft_log("  Cycle %-7d Player %d --- %-5s : reg[%d] = reg[%d] - reg[%d] = %d \n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "sub", sub[2], sub[0], sub[1], dead_pool->i_champ->reg[sub[2]]);
}
