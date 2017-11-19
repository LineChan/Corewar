/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 23:14:44 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/19 00:34:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

//TODO : presentation

void 				ft_vm_log_add(t_dead_pool *dead_pool, unsigned int add[])
{
	ft_log("  Cycle %-7d Player %d --- %-5s : reg[%d] = reg[%d] + reg[%d] = %d \n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "add", add[2], add[0], add[1], dead_pool->i_champ->reg[add[2]]);
}
