/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_xor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 00:52:27 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/19 01:00:13 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

//TODO:presentation
void 				ft_vm_log_xor(t_dead_pool *dead_pool,
									unsigned char *ptr,
									unsigned int xor[])
{
	ft_log("  Cycle %-7d Player %d --- %-5s : reg[%d] = %d ^ %d \n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "xor", *ptr, xor[0], xor[1]);
}
