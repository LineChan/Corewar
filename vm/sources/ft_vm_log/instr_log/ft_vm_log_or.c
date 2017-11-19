/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 00:31:48 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/19 00:36:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void				ft_vm_log_or(t_dead_pool *dead_pool,
									unsigned char *ptr,
									unsigned int or[2])
{
	ft_log("  Cycle %-7d Player %d --- %-5s : reg[%d] = %d | %d \n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "or", *ptr, or[0], or[1]);
}
