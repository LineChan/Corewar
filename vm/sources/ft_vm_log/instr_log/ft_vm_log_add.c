/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 23:14:44 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/19 16:19:30 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

//TODO : presentation

void 				ft_vm_log_add(t_dead_pool *dead_pool, unsigned int add[])
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "add");
	ft_vm_log_arg(dead_pool);
	ft_log("\t\treg[%d] = %d --> [%d] & [%d]\n", add[2], dead_pool->i_champ->reg[add[2]], add[0], add[1]);
}
