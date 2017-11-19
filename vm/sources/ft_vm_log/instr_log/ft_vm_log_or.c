/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 00:31:48 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/19 16:13:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

// TODO : presentation
void				ft_vm_log_or(t_dead_pool *dead_pool,
									unsigned char *ptr,
									unsigned int or[2])
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "or");
	ft_vm_log_arg(dead_pool);
	ft_log("\t\treg[%d] = %d --> [%d] | [%d]\n", *ptr, dead_pool->i_champ->reg[*ptr], or[0], or[1]);
}